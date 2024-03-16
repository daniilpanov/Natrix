#include "Engine/AI/AI.hpp"
#include <string>

std::string searchMove(const std::string& position, uint8_t en_passant, bool w_l_castling, bool w_s_castling, bool b_l_castling, bool b_s_castling, uint8_t pieces, uint8_t depth, float move_ctr, int max_time_ms, bool use_opening_book) {
    Position pos = {position, en_passant, w_l_castling, w_s_castling, b_l_castling, b_s_castling, move_ctr};
    AI ai("../data/AI/opening_book.txt");
    Move move = ai.best_move(pos, pieces, 1, max_time_ms, depth, use_opening_book);
    pos.move(move);
    return move.toChessNotation();
}

int main(int argc, char *argv[]) {
    if (argc < 12) {
        return 1;
    }

    char *endptr;
    std::cout << searchMove(
        argv[1],
        static_cast<uint8_t>(std::strtol(argv[2], &endptr, 10)),
        std::strtol(argv[3], &endptr, 10),
        std::strtol(argv[4], &endptr, 10),
        std::strtol(argv[5], &endptr, 10),
        std::strtol(argv[6], &endptr, 10),
        std::strtol(argv[7], &endptr, 10),
        std::strtol(argv[8], &endptr, 10),
        std::strtol(argv[9], &endptr, 10) / 2.0f,
        std::strtol(argv[10], &endptr, 10),
        std::strtol(argv[11], &endptr, 10)
    );
    return 0;
}
