#include "ui.h"

ui::ui()
    : m_length(0)
    , m_height(0)
{
    for (uint32_t i = static_cast<uint32_t>(CompetitorId::Tortoise);
         i < static_cast<uint32_t>(CompetitorId::Total); ++i)
    {
        previous_position.emplace_back(static_cast<CompetitorId>(i), 1);
        current_position.emplace_back(static_cast<CompetitorId>(i), 1);
        shift_range.emplace_back(static_cast<CompetitorId>(i), 0);
    }

    Tortise_shift = Hare_shift = Robo_shift = Frog_shift = 0;
}

ui::~ui()
{
}

void ui::update(const std::vector<Track::CompetitorPosition> &positions)
{
    for (uint32_t i = static_cast<uint32_t>(CompetitorId::Tortoise);
         i < static_cast<uint32_t>(CompetitorId::Total); ++i)
    {
        previous_position[i].second = current_position[i].second;
        current_position[findIndex(current_position, static_cast<CompetitorId>(i))].second =
            positions[findIndex(positions, static_cast<CompetitorId>(i))].second;
        shift_range[i].second = current_position[i].second - previous_position[i].second;
    }
}

void ui::set_length(int32_t l)
{
    m_length = l;
}

void ui::finish(const std::vector<Winner> &winners)
{
    for (uint32_t i = static_cast<uint32_t>(CompetitorId::Tortoise);
         i < static_cast<uint32_t>(CompetitorId::Total); ++i)
    {
        previous_position[i].second = 1;
        current_position[i].second = 1;
    }

    winner = "THE WINNERS: ";
    for (const auto &w : winners)
    {
        winner += w.second + " ";
    }
}

int ui::getShift(CompetitorId id)
{
    switch (id)
    {
    case CompetitorId::Tortoise:
        return shift_range[0].second;
    case CompetitorId::Hare:
        return shift_range[1].second;
    case CompetitorId::Robo:
        return shift_range[2].second;
    case CompetitorId::Frog:
        return shift_range[3].second;
    }
    return 0;
}

std::string ui::getWinner()
{
    return winner;
}

uint32_t ui::findIndex(const std::vector<Track::CompetitorPosition> &vector, CompetitorId id)
{
    for (uint32_t i = 0; i < vector.size(); ++i)
    {
        if (vector[i].first == id)
        {
            return i;
        }
    }
    return 0;
}
