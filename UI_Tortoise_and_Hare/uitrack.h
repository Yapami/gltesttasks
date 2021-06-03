#ifndef UITRACK_H
#define UITRACK_H

#include <QObject>

#include "Race.h"
#include "ui.h"

#include "common.h"

class UITrack : public QObject
{
    Q_OBJECT

public:
    explicit UITrack(QObject *parent = nullptr);

    enum class QMLCompetitorId
    {
        QMLTortoise = static_cast<int>(CompetitorId::Tortoise),
        QMLHare = static_cast<int>(CompetitorId::Hare),
        QMLRobo = static_cast<int>(CompetitorId::Robo),
        QMLFrog = static_cast<int>(CompetitorId::Frog),
        QMLTotal = static_cast<int>(CompetitorId::Total),
    };
    Q_ENUM(QMLCompetitorId)

    Q_INVOKABLE int getShift(QMLCompetitorId id);

    Q_INVOKABLE bool update();
    Q_INVOKABLE void finish();
    Q_INVOKABLE QString getWinner();

private:
    ui track;
    Race *r;
    uint32_t lenth;
    int32_t Tortoise_shift;
    int32_t Hare_shift;
    int32_t Robo_shift;
    int32_t Frog_shift;
};

#endif // UITRACK_H
