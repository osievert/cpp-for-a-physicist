#include <iomanip>

#include "mazegen.hpp"

int main()
{
    const auto HEIGHT = 27;
    const auto WIDTH = 27;

    auto cfg = mazegen::Config {};
    cfg.ROOM_BASE_NUMBER = 25;
    cfg.ROOM_SIZE_MIN = 1;
    cfg.ROOM_SIZE_MAX = 1;
    cfg.EXTRA_CONNECTION_CHANCE = 0.0;
    cfg.WIGGLE_CHANCE = 0.5;
    cfg.DEADEND_CHANCE = 0.5;
    cfg.RECONNECT_DEADENDS_CHANCE = 0.5;
    cfg.CONSTRAIN_HALL_ONLY = true;

    auto constraints = mazegen::PointSet {{1, 1}, {WIDTH - 2, HEIGHT - 2}};
    auto gen = mazegen::Generator();

    gen.generate(WIDTH, HEIGHT, cfg, constraints);

    if (!gen.get_warnings().empty())
    {
        std::cout << gen.get_warnings() << std::endl;
    }

    for (int y = 0; y < gen.maze_height(); y++)
    {
        for (int x = 0; x < gen.maze_width(); x++)
        {
            auto region = gen.region_at(x, y);
            if (region == mazegen::NOTHING_ID)
            {
                std::cout << "   ";
            }
            else if (constraints.find(mazegen::Point{x, y}) != constraints.end())
            {
                std::cout << "   ";
            }
            else if (mazegen::is_door(region))
            {
                std::cout << " ▣ ";
            }
            else
            {
                std::cout << " ▢ ";
            }
        }

        std::cout << std::endl;
    }

    return 0;
}
