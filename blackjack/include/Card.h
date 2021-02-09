
#ifndef CARD_H
#define CARD_H


enum class CardRank{
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
    ace,

    max_ranks
};

enum class CardSuit{
    clubs,
    diamonds,
    hearts,
    spades,

    max_suits
};

class Card{
private:
    CardRank m_rank {};
    CardSuit m_suit {};

public:
    Card(CardRank rank=CardRank::ace, CardSuit suit=CardSuit::clubs) :
        m_rank{rank}, m_suit{suit} {}

    CardRank getRank(){
        return m_rank;
    }

    CardSuit getSuit(){
        return m_suit;
    }

    void print () const;
    unsigned short value () const;

};



#endif /* ifndef  */




