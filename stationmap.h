#ifndef STATIONMAP_H
#define STATIONMAP_H

#include <vector>
#include "defines.h"
#include <algorithm>
#include <memory>

//https://www.programmersforum.ru/showthread.php?t=252350

struct PointOnMap {
    int id;
    float x;
    float y;
};

struct Edge {
    int id;
    int source;
    int target;
    PointOnMap start;
//    std::shared_ptr<PointOnMap> start;
//    std::shared_ptr<PointOnMap> end;
    PointOnMap end;
    float length;
};

class StationMap
{
public:
    StationMap();
    void addEdge(const Edge &new_edge);
    Edge getEdge(const int edge_id);
    void deleteEdge(int edge_id);
    Edge getChildEdge(int edge_id);
    void addPoint(const PointOnMap & point);
    PointOnMap getPoint(const int point_id);
    void findParents();

private:
    std::vector<PointOnMap>Points;
    std::vector<Edge>Edges;
};

#endif // STATIONMAP_H
