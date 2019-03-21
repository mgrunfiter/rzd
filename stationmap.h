#ifndef STATIONMAP_H
#define STATIONMAP_H

#include <vector>
#include <algorithm>
#include <memory>
#include <iostream>
#include "defines.h"
#include "logger.h"


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
    PointOnMap *start;
    PointOnMap *end;
    float length;
};

class StationMap
{
public:
    StationMap();
    ~StationMap();
    void addOneEdge(Edge *new_edge);
    Edge *getOneEdge(const int edge_id);
    void deleteOneEdge(int edge_id);
    Edge getChildEdge(int edge_id);
    void addOnePoint(PointOnMap *point);
    PointOnMap *getOnePoint(const int point_id);
    bool EdgesEmpty();
    int CountEdges();
    void findParents();
    void ClearData();

    std::vector<Edge *> getEdges();
    std::vector<PointOnMap *> getPoints();

private:
    std::vector<PointOnMap *> Points;
    std::vector<Edge *> Edges;
};

#endif // STATIONMAP_H
