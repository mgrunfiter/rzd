#include "stationmap.h"

StationMap::StationMap()
{

}

void StationMap::addEdge(const Edge &new_edge)
{
    Edges.push_back(new_edge);
}

Edge StationMap::getEdge(const int edge_id)
{
    auto edge_it = std::find_if(Edges.begin(), Edges.end(), [&](const Edge& edge){return (edge_id == edge.id);});
    return *edge_it;
}

void StationMap::addPoint(const PointOnMap &point)
{
    Points.push_back(point);
    //    std::sort(Points.begin(), Points.end(), [](PointOnMap a, PointOnMap b) { return a.id < b.id; });
}

PointOnMap StationMap::getPoint(const int point_id)
{
//    auto points_it = std::find_if(Points.begin(), Points.end(), [&](const PointOnMap& finded_point){return (point_id == finded_point.id);});
    auto points_it = std::find_if(Points.begin(), Points.end(), [&](const PointOnMap& point){return (point_id == point.id);});
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
