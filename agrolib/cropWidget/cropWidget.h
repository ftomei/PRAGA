#ifndef CROPWIDGET_H
#define CROPWIDGET_H

#ifndef MAX_YEARS
    #define MAX_YEARS 5
#endif

    #include <QWidget>
    #include <QComboBox>
    #include <QGroupBox>
    #include <QLineEdit>
    #include <QLabel>
    #include <QSqlDatabase>

    #include "criteria1DCase.h"
    #include "tabLAI.h"
    #include "tabRootDepth.h"
    #include "tabRootDensity.h"
    #include "tabIrrigation.h"
    #include "tabWaterContent.h"

    class Crit3DCropWidget : public QWidget
    {
        Q_OBJECT

        public:
            Crit3DCropWidget();
            void on_actionOpenProject();
            void on_actionOpenCropDB();
            void on_actionChooseCrop(QString cropName);
            void on_actionOpenMeteoDB();
            void on_actionOpenSoilDB();
            void on_actionChooseMeteo(QString idMeteo);
            void on_actionChooseFirstYear(QString year);
            void on_actionChooseLastYear(QString year);
            void on_actionChooseSoil(QString soilCode);
            void on_actionDeleteCrop();
            void on_actionRestoreData();
            void on_actionNewCrop();
            void on_actionSave();
            void on_actionUpdate();
            bool saveCrop();
            void updateMeteoPointValues();
            void updateCropParam(QString idCrop);
            bool updateCrop();
            bool updateMeteoPoint();
            void updateTabLAI();
            void updateTabRootDepth();
            void updateTabRootDensity();
            void updateTabIrrigation();
            void updateTabWaterContent();
            void tabChanged(int index);
            bool checkIfCropIsChanged();
            void irrigationVolumeChanged();
            void variableWaterContentChanged();

        private:
            QSqlDatabase dbCrop;
            QSqlDatabase dbMeteo;
            QSqlDatabase dbSoil;
            Crit1DCase myCase;
            Crit3DCrop cropFromDB;
            soil::Crit3DTextureClass textureClassList[13];
            soil::Crit3DFittingOptions fittingOptions;
            QString tableMeteo;
            bool cropChanged;
            double meteoLatBackUp;
            QStringList yearList;

            QGroupBox *infoCropGroup;
            QGroupBox *infoMeteoGroup;
            QGroupBox *infoSoilGroup;
            QGroupBox *laiParametersGroup;
            QGroupBox *rootParametersGroup;
            QGroupBox *irrigationParametersGroup;
            QGroupBox *waterStressParametersGroup;
            QGroupBox *waterContentGroup;
            QComboBox cropListComboBox;
            QComboBox meteoListComboBox;
            QComboBox soilListComboBox;
            QComboBox firstYearListComboBox;
            QComboBox lastYearListComboBox;
            QLineEdit* cropIdValue;
            QLineEdit* cropTypeValue;
            QLineEdit* maxKcValue;
            QLabel cropSowing;
            QLabel cropCycleMax;
            QSpinBox *cropSowingValue;
            QSpinBox* cropCycleMaxValue;
            QDoubleSpinBox* latValue;
            QDoubleSpinBox* LAIminValue;
            QDoubleSpinBox* LAImaxValue;
            QLabel *LAIgrass;
            QLineEdit* LAIgrassValue;
            QLineEdit* thermalThresholdValue;
            QLineEdit* upperThermalThresholdValue;
            QLineEdit* degreeDaysEmergenceValue;
            QLineEdit* degreeDaysLAIincValue;
            QLineEdit* degreeDaysLAIdecValue;
            QLineEdit* LAIcurveAValue;
            QLineEdit* LAIcurveBValue;
            QLineEdit* rootDepthZeroValue;
            QLineEdit* rootDepthMaxValue;
            QComboBox* rootShapeComboBox;
            QDoubleSpinBox* shapeDeformationValue;
            QLabel *degreeDaysInc;
            QLineEdit* degreeDaysIncValue;
            QLineEdit* irrigationVolumeValue;
            QSpinBox* irrigationShiftValue;
            QLineEdit* degreeDaysStartValue;
            QLineEdit* degreeDaysEndValue;
            QLineEdit* psiLeafValue;
            QDoubleSpinBox* rawFractionValue;
            QDoubleSpinBox* stressToleranceValue;
            QRadioButton *volWaterContent;
            QRadioButton *degreeSat;
            QTabWidget* tabWidget;
            QAction* saveChanges;
            QAction* restoreData;
            QPushButton *saveButton;
            QPushButton *updateButton;

            TabLAI* tabLAI;
            TabRootDepth* tabRootDepth;
            TabRootDensity* tabRootDensity;
            TabIrrigation* tabIrrigation;
            TabWaterContent* tabWaterContent;

            void clearCrop();
            void checkCropUpdate();
            void openCropDB(QString newDbCropName);
            void openMeteoDB(QString dbMeteoName);
            void openSoilDB(QString dbSoilName);
    };


#endif // CROPWIDGET_H