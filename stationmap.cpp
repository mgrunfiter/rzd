#include "stationmap.h"

StationMap::StationMap()
{

}

StationMap::~StationMap()
{
    qDebug() << "d-tor StationMap ";
    ClearData();
//    // освобождаем выделенную под объекты память
//    for(size_t i = 0; i < Edges.size(); ++i)
//       delete [] Edges[i];
//    // освобождаем выделенную под объекты память
//    for(size_t i = 0; i < Points.size(); ++i)
//       delete [] Points[i];
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
    //    std::sort(Points.begin(), Points.end(), [](PointOnMap a, PointOnMap b) { return a.id < b.id; });
}

PointOnMap* StationMap::getOnePoint(const int point_id)
{
//    auto points_it = std::find_if(Points.begin(), Points.end(), [&](const PointOnMap& finded_point){return (point_id == finded_point.id);});
    auto points_it = std::find_if(Points.begin(), Points.end(), [&](PointOnMap* point){return (point_id == point->id);});
    return *points_it;
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
    // освобождаем выделенную под объекты память
    for(size_t i = 0; i < Edges.size(); ++i)
       delete [] Edges[i];
    // освобождаем выделенную под объекты память
    for(size_t i = 0; i < Points.size(); ++i)
       delete [] Points[i];
}

std::vector<Edge *> StationMap::getEdges()
{
    return Edges;
}
