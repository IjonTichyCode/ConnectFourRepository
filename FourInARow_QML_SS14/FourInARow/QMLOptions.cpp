#include "QMLOptions.h"
#include "GameDataModel.h"
#include "FIARApplicationSetup.h"
#include "fourinarowapplication.h"

QMLOptions::QMLOptions(QQuickItem *parent) :
    QQuickItem(parent),
    setupCompleted(false)
{

}

void QMLOptions::qmlComponentCompleted()
{
    const FIARApplicationSetup & appSetup = GameDataModel::getInstance()->getAppSetup();

    setAntialiasingOption(appSetup.antialiasing);
    setFullscreenOption(appSetup.fullscreen);
    setBoardDesignOption(appSetup.design);
    setColor0Option(appSetup.color0);
    setColor1Option(appSetup.color1);
    FourInARowApplication::getInstance()->setLanguage(appSetup.language);
    setLanguageOption(appSetup.language);

    setupCompleted = true;
}

void QMLOptions::antialiasingSet(bool antialiasing)
{
    if (setupCompleted) {
        GameDataModel::getInstance()->getAppSetup().antialiasing = antialiasing;
    }
}

void QMLOptions::fullscreenSet(bool fullscreen)
{
    if (setupCompleted) {
        GameDataModel::getInstance()->getAppSetup().fullscreen = fullscreen;
    }
}

void QMLOptions::boardDesignSet(int design)
{
    if (setupCompleted) {

        GameDataModel::getInstance()->getAppSetup().design = design;
    }
}

void QMLOptions::color0Set(float color)
{
    if (setupCompleted) {
        GameDataModel::getInstance()->getAppSetup().color0 = color;
    }
}

void QMLOptions::color1Set(float color)
{
    if (setupCompleted) {
        GameDataModel::getInstance()->getAppSetup().color1 = color;
    }
}

void QMLOptions::languageSet(int language)
{
    if (setupCompleted) {
        GameDataModel::getInstance()->getAppSetup().language = language;
        FourInARowApplication::getInstance()->setLanguage(language);
    }
}
