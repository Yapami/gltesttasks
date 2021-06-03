#ifndef UI_H
#define UI_H

#include <map>

#include "Race.h"
#include "Track.h"

#include <QObject>

class ui : public Track
{
public:
    ui();
    ~ui() override;

    void set_length(int32_t l) override;
    void update(const std::vector<CompetitorPosition> &positions) override;
    void finish(const std::vector<Winner> &winners) override;

    int getShift(CompetitorId id);

    std::string getWinner();

signals:

private:
    int32_t m_length;
    int32_t m_height;
    std::vector<Track::CompetitorPosition> previous_position;
    std::vector<Track::CompetitorPosition> current_position;

    std::vector<Track::CompetitorPosition> shift_range; ///////////////

    uint32_t findIndex(const std::vector<CompetitorPosition> &vector, CompetitorId id);

    ////////////////////////////////////
    int32_t Tortise_shift;
    int32_t Hare_shift;
    int32_t Robo_shift;
    int32_t Frog_shift;

    std::string winner;
};

#endif // UI_H
