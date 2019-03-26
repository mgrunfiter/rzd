#ifndef STATIONMAP_H
#define STATIONMAP_H

#include <vector>
#include <queue>
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
    std::vector<int> sources;
    std::vector<int> targets;
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
    Edge *GetOneEdge(const int edge_id);
    Edge *GetOneEdgeByPointStart(PointOnMap *PointStart);
    Edge *GetOneEdgeByPointEnd(PointOnMap *PointEnd);
    void DeleteOneEdge(int edge_id);
    Edge GetChildEdge(int edge_id);
    void AddOnePoint(PointOnMap *point);
    PointOnMap *GetOnePoint(const int point_id);
    bool EdgesEmpty();
    unsigned long CountEdges();
    void FindParents();
    void ClearData();
    bool FindRoute(Edge *EdgeStart, Edge *EdgeEnd);

    std::vector<Edge *> GetEdges();
    std::vector<PointOnMap *> GetPoints();

private:
    std::vector<PointOnMap *> Points;
    std::vector<Edge *> Edges;
    std::vector<Edge *> Route;
};

#endif // STATIONMAP_H
