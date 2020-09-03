#ifndef CSVTOSHAPEPROJECT_H
#define CSVTOSHAPEPROJECT_H

#include <QString>
#include <fstream>
#include <QSqlDatabase>
#include "logger.h"
#include "criteria1DUnit.h"
#include "criteriaOutputVariable.h"
#include "criteriaAggregationVariable.h"
#include "shapeHandler.h"

#define ERROR_SETTINGS_MISSING -1
#define ERROR_SETTINGS_WRONGFILENAME -2
#define ERROR_SETTINGS_MISSINGDATA -3
#define ERROR_DBPARAMETERS -5
#define ERROR_DBHISTORICAL -6
#define ERROR_TDXWRITE -7
#define ERROR_DBOUTPUT -10
#define ERROR_WRONGDATE -11
#define ERROR_PARSERCSV -12
#define ERROR_READ_UNITS -15

#define ERROR_DB_MISSING_DATA -20
#define ERROR_DB_INCOMPLETE_DATA -21
#define ERROR_DB_MISSING_PRECOMPUTED_DTX -22

#define ERROR_WRITECSV -50
#define ERROR_OUTPUT_VARIABLES -60
#define ERROR_SHAPEFILE -70
#define ERROR_ZONAL_STATISTICS_SHAPE -80
#define ERROR_MISSING_GDAL -100


class CriteriaOutputProject
{
public:
    bool isProjectLoaded;

    QString path;
    QString projectName;
    QString configFileName;
    QString projectError;
    QString ucmFileName;
    QString fieldListFileName;
    QString variableListFileName;
    QString aggregationShapeFileName;
    QString shapeFieldName;
    QString aggregationCellSize;
    QString aggregationListFileName;

    QString outputCsvFileName;
    QString outputShapeFileName;
    QString outputShapeFilePath;
    QString outputAggrCsvFileName;

    QDate dateComputation;

    QString dbUnitsName;
    QString dbDataName;
    QString dbCropName;
    QString dbDataHistoricalName;

    QSqlDatabase dbCrop;
    QSqlDatabase dbData;
    QSqlDatabase dbDataHistorical;

    int nrUnits;
    std::vector<Crit1DUnit> unitList;
    CriteriaOutputVariable outputVariable;
    CriteriaAggregationVariable aggregationVariable;

    QFile outputFile;
    QString logFileName;
    std::ofstream logFile;
    Logger logger;

    CriteriaOutputProject();

    void initialize();
    void closeProject();
    int initializeProject(QString settingsFileName, QDate dateComputation);
    int initializeProjectDtx();
    int initializeProjectCsv();

    bool readSettings();

    int precomputeDtx();
    int createCsvFile();
    int createShapeFile();
    int createAggregationFile();
    int createMaps();

    bool initializeCsvOutputFile();

};


#endif // CSVTOSHAPEPROJECT_H
