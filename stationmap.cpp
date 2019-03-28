#include "stationmap.h"

StationMap::StationMap()
{

}

StationMap::~StationMap()
{
    qDebug() << "d-tor StationMap ";
    ClearData();
}

void StationMap::addOneEdge(Edge *new_edge)
{
    Edges.push_back(new_edge);
}

Edge* StationMap::GetOneEdge(const int edge_id)
{
    auto edge_it = std::find_if(Edges.begin(), Edges.end(), [&](Edge* edge){return (edge_id == edge->id);});
    return *edge_it;
}

Edge *StationMap::GetOneEdgeByPointStart(PointOnMap *PointStart)
{
    auto edge_it = std::find_if(Edges.begin(), Edges.end(), [&](Edge* edge){return (PointStart == edge->start);});
    return *edge_it;
}

Edge *StationMap::GetOneEdgeByPointEnd(PointOnMap *PointEnd)
{
    auto edge_it = std::find_if(Edges.begin(), Edges.end(), [&](Edge* edge){return (PointEnd == edge->end);});
    return *edge_it;
}

void StationMap::AddOnePoint(PointOnMap *point)
{
    Points.push_back(point);
}

PointOnMap* StationMap::GetOnePoint(const int point_id)
{
    auto point_it = std::find_if(Points.begin(), Points.end(), [&](PointOnMap* point){return (point_id == point->id);});
    return *point_it;
}

bool StationMap::EdgesEmpty()
{
    return Edges.empty();
}

bool StationMap::RouteEmpty()
{
    return Route.empty();
}

unsigned long StationMap::CountEdges()
{
    return Edges.size();
}

void StationMap::FindParents()
{
    for (unsigned int i = 0; i < Edges.size(); i++)
    {
        for (unsigned int j = 0; j <  Edges.size(); j++)
        {
            if (Edges[i]->id != Edges[j]->id)
            {
                if (Edges[i]->start == Edges[j]->end)
                    Edges[i]->sources.push_back(Edges[j]->id);
                if (Edges[i]->end == Edges[j]->start)
                    Edges[i]->targets.push_back(Edges[j]->id);
            }
        }
    }
}

void StationMap::ClearData()
{
    qDebug() << "Clear data";
    qDebug() << "Edges size = " << Edges.size() << "\tEdges capacity: " << Edges.capacity();
    qDebug() << "Points size = " << Points.size() << "\tPoints capacity: " << Points.capacity();
    Edges.clear();
    Points.clear();
    Route.clear();
    std::vector<Edge *>().swap(Edges);
    std::vector<Edge *>().swap(Route);
    std::vector<PointOnMap *>().swap(Points);
    qDebug() << "Edges size = " << Edges.size() << "\tEdges capacity: " << Edges.capacity();
    qDebug() << "Points size = " << Points.size() << "\tPoints capacity: " << Points.capacity();
}

/*
Поиск в ширину

Cначала обрабатываются все вершины, смежные с текущей, а лишь потом – их потомки.
Для запоминания еще не обработанных вершин используется очередь.
Последовательность действий:

1 задать стартовую вершину (аналог корневой вершины при обходе дерева)
2 обработать стартовую вершину и включить ее во вспомогательный список обработанных вершин
3 включить в очередь все вершины, смежные со стартовой
4 организовать цикл по условию опустошения очереди и внутри цикла выполнить:
    1 извлечь из очереди очередную вершину
    2 проверить по вспомогательному списку обработанность этой вершины
    3 если вершина уже обработана, то извлечь из очереди следующую вершину
    4 если вершина еще не обработана, то обработать ее и поместить в список обработанных вершин
5   просмотреть весь список смежных с нею вершин и поместить в очередь все еще не обработанные вершины
*/

bool StationMap::FindRoute(Edge * EdgeStart, Edge * EdgeEnd)
{
    Profiler pfr("FindRoute W");
    qDebug() << "EdgeStart ID = " << EdgeStart->id;
    qDebug() << "EdgeEnd ID = " << EdgeEnd->id;
    bool Flag = false;
    Route.clear();
    std::vector<Edge *>().swap(Route);
    std::queue <int> turn;   // Это наша очеред
    std::vector <int> done;  // Список обработанных вершин
    if (EdgeStart->id != EdgeEnd->id)
    {
        for (auto OneEdgeID: EdgeStart->targets)
        {
            turn.push(OneEdgeID);
        }
        done.push_back(EdgeStart->id);
    }
    while (!turn.empty())
    {
        int ind = turn.front();
        turn.pop();
        std::vector<int>::iterator it = std::find(done.begin(), done.end(), ind);
        qDebug() << *it;
        qDebug() << (it-done.begin());
        if (it != done.end())
        {
            continue;
        }
        Edge *CurrentEdge = GetOneEdge(ind);
        if (CurrentEdge->id == EdgeEnd->id)
        {
            // Конец маршрута, нашли
            done.push_back(CurrentEdge->id);
            // TODO выкинуть тупиковые ребра из done

            //
            for (auto OneEdgeID: done)
            {
                qDebug() << "ID=" << OneEdgeID;
                Route.push_back(GetOneEdge(OneEdgeID));
            }
            Flag = true;
            break;
        }
        else
        {
            for (auto OneEdgeID: CurrentEdge->targets)
            {
                turn.push(OneEdgeID);
            }
            done.push_back(CurrentEdge->id);
        }

    }
    qDebug() << "end FindRoute";
    return Flag;
}


/*
Поиск в глубину

Поиск в глубину использует две структуры – стек для запоминания еще не обработанных вершин и список для запоминания уже обработанных.
Поиск выполняется следующим образом:

1 задать стартовую вершину (аналог корневой вершины при обходе дерева)
2 обработать стартовую вершину и включить ее во вспомогательный список обработанных вершин
3 включить в стек все вершины, смежные со стартовой
4 организовать цикл по условию опустошения стека и внутри цикла выполнить:
    1 извлечь из стека очередную вершину
    2 проверить по вспомогательному списку обработанность этой вершины
    3 если вершина уже обработана, то извлечь из стека следующую вершину
    4 если вершина еще не обработана, то обработать ее и поместить в список обработанных вершин
    5 просмотреть весь список смежных с нею вершин и поместить в стек все еще не обработанные вершины
*/
/*
bool StationMap::FindRoute(Edge * EdgeStart, Edge * EdgeEnd)
{
    Profiler pfr("FindRoute D");
    //TODO
    qDebug() << "EdgeStart ID = " << EdgeStart->id;
    qDebug() << "EdgeEnd ID = " << EdgeEnd->id;   

    bool Flag = false;
    Route.clear();
    std::vector<Edge *>().swap(Route);
    std::stack <int> turn;   // Это наш стек
    std::vector <int> done;  // Список обработанных вершин
    if (EdgeStart->id != EdgeEnd->id)
    {
        for (auto OneEdgeID: EdgeStart->targets)
        {
            turn.push(OneEdgeID);
        }
        done.push_back(EdgeStart->id);
    }
    while (!turn.empty())
    {
        int ind = turn.top();
        turn.pop();
        std::vector<int>::iterator it = std::find(done.begin(), done.end(), ind);
        qDebug() << *it;
        qDebug() << (it-done.begin());
        if (it != done.end())
        {
            continue;
        }
        Edge *CurrentEdge = GetOneEdge(ind);
        if (CurrentEdge->id == EdgeEnd->id)
        {
            // Конец маршрута, нашли
            done.push_back(CurrentEdge->id);
            for (auto OneEdgeID: done)
            {
                qDebug() << "ID=" << OneEdgeID;
                Route.push_back(GetOneEdge(OneEdgeID));
            }
            Flag = true;
            break;
        }
        else
        {
            for (auto OneEdgeID: CurrentEdge->targets)
            {
                turn.push(OneEdgeID);
            }
            done.push_back(CurrentEdge->id);
        }

    }
    qDebug() << "end FindRoute";
    return Flag;
}
*/

std::vector<Edge *> StationMap::GetEdges()
{
    return Edges;
}

std::vector<Edge *> StationMap::GetEdgesRoute()
{
    return Route;
}

std::vector<PointOnMap *> StationMap::GetPoints()
{
    return Points;
}
