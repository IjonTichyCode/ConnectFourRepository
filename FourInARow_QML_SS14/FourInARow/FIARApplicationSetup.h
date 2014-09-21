#ifndef FIARAPPLICATIONSETUP_H
#define FIARAPPLICATIONSETUP_H


/**
 * @brief The FIARApplicationSetup class hold a record
 * of values that describe the state of the applicationn in general.
 */
class FIARApplicationSetup
{
public:
    FIARApplicationSetup();

    bool fullscreen;
    bool antialiasing;
    int width;
    int height;
    int player0Id;
    int player1Id;
    int design;
    float color0;
    float color1;
    bool useTimer;
    int maxTime;
    int columns;
    int rows;
    int language;

};

#endif // FIARAPPLICATIONSETUP_H
