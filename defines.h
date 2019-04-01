#ifndef DEFINES_H
#define DEFINES_H

#include <QString>

const QString PROGRAMM_NAME = "Station_map";
const QString VERSION = "v0.1";
const QString FULL_PROGRAMM_NAME = PROGRAMM_NAME + " " + VERSION;
const QString LOG_NAME = PROGRAMM_NAME + "_" + VERSION + ".log";

double const EPSILON = 0.0;

double const MAX_X = 10000;
double const MIN_X = 0;
double const MAX_Y = 10000;
double const MIN_Y = 0;

int const INVALID = -1;

#endif // DEFINES_H
