#include "Engine/AI/AI.hpp"
#include <emscripten/bind.h>

Move search_move_special(const std::string& position, uint8_t en_passant, bool w_l_castling, bool w_s_castling, bool b_l_castling, bool b_s_castling, uint8_t pieces, uint8_t depth, float move_ctr) {
    Position pos = {position, en_passant, w_l_castling, w_s_castling, b_l_castling, b_s_castling, move_ctr};
    AI ai;
    return ai.best_move_special(pos, pieces, depth);
}
Move search_move(const std::string& position, uint8_t en_passant, bool w_l_castling, bool w_s_castling, bool b_l_castling, bool b_s_castling, uint8_t pieces, float move_ctr) {
    Position pos = {position, en_passant, w_l_castling, w_s_castling, b_l_castling, b_s_castling, move_ctr};
    AI ai;
    return ai.best_move(pos, pieces, 0, 600);
}

using namespace emscripten;

EMSCRIPTEN_BINDINGS(Natrix)
{
    function("search_move_special", &search_move_special),
    function("search_move", &search_move);
}
