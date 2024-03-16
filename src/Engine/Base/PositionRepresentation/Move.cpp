#include "Move.hpp"


Move::Move() = default;
Move::Move(uint8_t from, uint8_t to, uint8_t attacker_type, uint8_t attacker_side, uint8_t defender_type, uint8_t defender_side, uint8_t flag) {
    this->_from = from;
    this->_to = to;

    this->_attacker_type = attacker_type;
    this->_attacker_side = attacker_side;

    this->_defender_type = defender_type;
    this->_defender_side = defender_side;

    this->_flag = flag;
}
bool operator ==(Move left, Move right) {
    return (left._from == right._from and left._to == right._to and left._attacker_type == right._attacker_type and left._attacker_side == right._attacker_side and left._defender_type == right._defender_type and left._defender_side == right._defender_side and left._flag == right._flag);
}

std::string Move::toChessNotation() const {
    std::string notation;
    // Определение типа фигуры
    std::string piece;
    if (_attacker_side == 0) {
        switch (_attacker_type) {
            case 0:
                piece = "P";
                break;
            case 1:
                piece = "N";
                break;
            case 2:
                piece = "B";
                break;
            case 3:
                piece = "R";
                break;
            case 4:
                piece = "Q";
                break;
            case 5:
                piece = "K";
                break;
        }
    } else {
        switch (_attacker_type) {
            case 0:
                piece = "p";
                break;
            case 1:
                piece = "n";
                break;
            case 2:
                piece = "b";
                break;
            case 3:
                piece = "r";
                break;
            case 4:
                piece = "q";
                break;
            case 5:
                piece = "k";
                break;
        }
    }
    // Определение начальной и конечной клеток
    std::string start_square = std::string(1, _from % 8 + 'a') + std::to_string(_from / 8 + 1);
    std::string end_square = std::string(1, _to % 8 + 'a') + std::to_string(_to / 8 + 1);
    // Добавление взятия на проходе
    if (_flag == Flag::EnPassantCapture) {
        notation += start_square.substr(0, 1) + "x" + end_square;
    } else {
        notation += piece + start_square + end_square;
    }
    // Добавление обозначения шаха и матов
    if (_flag >= 7) {
        switch (_flag) {
            case Flag::PromoteToKnight:
                notation += "N";
                break;
            case Flag::PromoteToBishop:
                notation += "B";
                break;
            case Flag::PromoteToRook:
                notation += "R";
                break;
            case Flag::PromoteToQueen:
                notation += "Q";
                break;
        }
    } else if (_flag >= 3) {
        notation += (_flag == Flag::WhiteLongCastling || _flag == Flag::BlackLongCastling) ? "O-O-O" : "O-O";
    }
    return notation;
}
