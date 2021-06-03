#include "uitrack.h"

UITrack::UITrack(QObject *parent)
    : QObject(parent)
    , track()
    , lenth(70)

{
    r = new Race(lenth, track);
}

int UITrack::getShift(UITrack::QMLCompetitorId id)
{
    return track.getShift(static_cast<CompetitorId>(id));
}

bool UITrack::update()
{
    return r->update() != Race::State::Finish;
}

void UITrack::finish()
{
    delete r;
    r = new Race(lenth, track);
}

QString UITrack::getWinner()
{
    return QString::fromUtf8(track.getWinner().c_str());
}
