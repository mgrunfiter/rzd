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

Edge* StationMap::getOneEdge(const int edge_id)
{
    auto edge_it = std::find_if(Edges.begin(), Edges.end(), [&](Edge* edge){return (edge_id == edge->id);});
    return *edge_it;
}

void StationMap::addOnePoint(PointOnMap *point)
{
    Points.push_back(point);
}

PointOnMap* StationMap::getOnePoint(const int point_id)
{
    auto point_it = std::find_if(Points.begin(), Points.end(), [&](PointOnMap* point){return (point_id == point->id);});
    return *point_it;
}

bool StationMap::EdgesEmpty()
{
    return Edges.empty();
}

void StationMap::findParents()
{
// TODO: ?
//    for (auto current_edge: Edges)
//    {
//        auto edge_it = std::find_if(Edges.begin(), Edges.end(), [&](const Edge& edge){return (current_edge.start == edge.end);});
//        current_edge.source = edge_it->id;
    //    }
}

void StationMap::ClearData()
{
    qDebug() << "Clear data";
    qDebug() << "Edges size = " << Edges.size() << "\tEdges capacity: " << Edges.capacity();
    qDebug() << "Points size = " << Points.size() << "\tPoints capacity: " << Points.capacity();
    // освобождаем выделенную под объекты память
    for(size_t i = 0; i < Edges.size(); ++i)
       delete [] Edges[i];
    // освобождаем выделенную под объекты память
    for(size_t i = 0; i < Points.size(); ++i)
       delete [] Points[i];
    qDebug() << "Edges size = " << Edges.size() << "\tEdges capacity: " << Edges.capacity();
    qDebug() << "Points size = " << Points.size() << "\tPoints capacity: " << Points.capacity();
    Edges.clear();
    Points.clear();
    std::vector<Edge *>().swap(Edges);
    std::vector<PointOnMap *>().swap(Points);
    qDebug() << "Edges size = " << Edges.size() << "\tEdges capacity: " << Edges.capacity();
    qDebug() << "Points size = " << Points.size() << "\tPoints capacity: " << Points.capacity();
}

std::vector<Edge *> StationMap::getEdges()
{
    return Edges;
}

std::vector<PointOnMap *> StationMap::getPoints()
{
    return Points;
}
