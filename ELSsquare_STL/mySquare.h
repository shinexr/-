//
// Created by shinexr on 2022/3/30.
//

#ifndef UNTITLED_MYSQUARE_H
#define UNTITLED_MYSQUARE_H
#include <cstdint>
#include <list>
#include <set>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <string>
#include <utility>


namespace shinexr01
{
    using namespace std::placeholders;
    using std::pair;
    using std::list;
    using std::set;
    enum dircetion
    {
        left = -1,
        right = 1,
        down = 1,
        orgin = 0
    };
    enum GamePlace
    {
        PlaceWedth = 200,
        PlaceHeigh = 400,
        SquareWedth = 20,
        SquareHeigh = 20,
        SquareWNum = 10,
        SquareHNum = 20
    };

    template <typename T1, typename T2>
    class equal1st
    {
    public:
        bool operator () (const pair<T1,T2>& lhs, const T1& rhs)const
        {
            return lhs.first == rhs;
        }
    };

    template <typename T1, typename T2>
    class equal2nd
    {
    public:
        bool operator () (const pair<T1,T2>& lhs, const T2& rhs) const
        {
            return lhs.second == rhs;
        }
    };

    template <typename T1, typename T2>
    class less2nd
    {
    public:
        void operator () (pair<T1,T2>& lhs, const T2& rhs)
        {
            if(lhs.second < rhs)
            {
                lhs.second +=1;
            }
        }
    };

    template<typename T1, typename T2>
    class setMoveXY
    {
    private:
        pair<T1,T2> offset;
    public:
        setMoveXY(const pair<T1,T2>& other):offset(other){}
        pair<T1,T2> operator () (pair<T1,T2> lhs)const
        {
            lhs.first += offset.first;
            lhs.second += offset.second;
            return lhs;
        }
    };
    template<typename T1, typename T2>
    class rotalSquares
    {
    public:
        pair<T1,T2> m_maxXY;
        pair<T1,T2> m_minXY;
    public:
        rotalSquares(const pair<T1,T2>& maxXY, const pair<T1,T2>& minXY):m_maxXY(maxXY),m_minXY(minXY){}
        pair<T1,T2> operator () (const pair<T1,T2> lhs)const
        {
            T1 tmpXNum, tmpYNum, tmpX, tmpY;

            tmpXNum = m_maxXY.first - m_minXY.first;
            tmpYNum = m_maxXY.second - m_minXY.second;

            tmpX = m_maxXY.second -lhs.second+m_minXY.first;
            tmpY = lhs.first-m_minXY.first+m_minXY.second;
#if 1
            if((tmpXNum - tmpYNum) == 3)
            {
                tmpY-=1;
                tmpX+=1;

            }else if(( tmpYNum -tmpXNum) == 3)
            {
                tmpX-=1;
                tmpY+=1;
            }
#endif
            return pair<T1,T2>(tmpX,tmpY);
        }
    };

    template<typename T1, typename T2>
    class squares
    {
    private:
        list<pair<T1,T2> > m_4Squares;
        list<pair<T1,T2> > m_fallSquares;
        pair<T1,T2> m_maxXY;
        pair<T1,T2> m_minXY;

        void initSquares(uint16_t xPos = 0 ,uint16_t squareLeftNum = 4)
        {
            int32_t preYNum = 0;
            int32_t preXNum;
            int32_t squareNum;

            if(squareLeftNum == 1)
            {
                squareNum = 1;
            }
            else
            {
                squareNum = rand() % 2 + 1;
            }
            squareLeftNum -= squareNum;

            if(xPos == 0)
            {
                for(int i = 0; i < squareNum; i++)
                {
                    m_4Squares.push_back(pair<T1,T2>(xPos,i));
                }
            }
            else
            {
                if(xPos == 2 && squareNum == 2)
                {
                    m_4Squares.clear();
                    initSquares(0, 4);
                }else
                {
                    preXNum = std::count_if(m_4Squares.begin(),m_4Squares.end(),
                                           // std::bind2nd(equal1st<T1,T2>(),xPos - 1)
                                            std::bind(std::function<bool(const pair<T1,T2>&, const T1 &)>(equal1st<T1,T2>()),_1,xPos -1));
                    preXNum = std::rand() % preXNum + 1;
                    auto itor = m_4Squares.begin();
                    for(int i = 0; i < preXNum; i++)
                    {
                        itor = std::find_if(itor,m_4Squares.end(),
                                            std::bind(std::function<bool(const pair<T1,T2>&, const T1 &)>(equal1st<T1,T2>()),_1,xPos -1));
                        preYNum = itor->second;
                        itor ++ ;
                    }
                    for (int i = 0; i < squareNum; ++i)
                    {
                        m_4Squares.push_back(std::pair<T1,T2>(xPos,preYNum + i));
                    }
                }
            }
            if(squareLeftNum > 0)
            {
                initSquares(xPos + 1, squareLeftNum);
            }
        }
        void MaxMinXY(const std::pair<T1,T2>& rhs)
        {
            m_maxXY.first = m_maxXY.first > rhs.first ? m_maxXY.first : rhs.first;
            m_minXY.first = m_minXY.first > rhs.first ? rhs.first : m_minXY.first;
            m_maxXY.second = m_maxXY.second > rhs.second ? m_maxXY.second : rhs.second;
            m_minXY.second = m_minXY.second > rhs.second ? rhs.second : m_minXY.second;
        }

    public:
        squares():m_4Squares(),m_fallSquares(),m_maxXY(0,0),m_minXY(0,0)
        {
            initSquares();
            setMaxMinXY(m_4Squares);
        }
        bool  checkBounds(dircetion xPosOffset, dircetion yPosOffset)const
        {
            bool tmp = (m_minXY.first + xPosOffset >=0) ;
            return ( (m_minXY.first + xPosOffset >=0) && (m_maxXY.first + xPosOffset < 10) && (m_maxXY.second + yPosOffset <= 19) ) ;
        }

        void setMaxMinXY(const pair<T1,T2>& maxXY, const pair<T1,T2>& minXY)
        {
            m_maxXY = maxXY;
            m_minXY = minXY;
        }
        void setMaxMinXY(const list<pair<T1,T2> >& squares)
        {
            if(squares.empty())
                return;
            auto item = squares.begin();
            m_maxXY.first = m_minXY.first = item->first;
            m_maxXY.second = m_minXY.second = item->second;
            while(++item != squares.end())
            {
                MaxMinXY(*item);
            }
        }
        bool isExist(const list<std::pair<T1,T2> >& squares)const
        {
            if(!m_fallSquares.empty())
            {
                for (auto item = squares.begin(); item != squares.end(); ++ item)
                {
                    if(std::find(m_fallSquares.begin(),m_fallSquares.end(),*item) != m_fallSquares.end())
                        return true;
                }
            }
            return false;
        }
        void move(const std::pair<T1,T2>& offset)
        {
            list<pair<T1,T2> > tmpSuqares(m_4Squares.size());
            std::transform(m_4Squares.begin(),m_4Squares.end(),     //source
                           tmpSuqares.begin(),                  //dest
                           std::function<pair<T1,T2> (pair<T1,T2>)>(setMoveXY<T1,T2>(offset)) );
            if( (checkBounds(dircetion(offset.first),dircetion(offset.second)) == true) && (isExist(tmpSuqares) == false))
            {
                m_4Squares.swap(tmpSuqares);
                setMaxMinXY(m_4Squares);
            }else if(offset.second == down)
            {
                std::copy(m_4Squares.begin(),m_4Squares.end(), std::inserter(m_fallSquares,m_fallSquares.begin()));
                int16_t x = m_minXY.second;
                for(int16_t i = m_maxXY.second; i >= x; --i)
                {
                    int16_t countY = std::count_if(m_fallSquares.begin(),m_fallSquares.end(),
                                              bind(std::function<bool(const pair<T1,T2>&, const T2&)>(equal2nd<T1,T2>()), _1,i));
                    if(countY == 10)
                    {
                        m_fallSquares.template remove_if(bind(std::function<bool(const pair<T1,T2>&, const T2&)>(equal2nd<T1,T2>()), _1,i));
                        std::for_each(m_fallSquares.begin(),m_fallSquares.end(),
                                      bind(std::function<void(pair<T1,T2>&, const T2&)>(less2nd<T1,T2>()), _1,i));
                        ++i;
                        --x;
                    }
                }
                m_4Squares.clear();
                initSquares();
                setMaxMinXY(m_4Squares);
            }
        }
        void rotal()
        {
            rotalSquares<T1,T2> tmp(m_maxXY,m_minXY);
            std::list<std::pair<T1,T2> > tmpSquares(m_4Squares.size());
            std::transform(m_4Squares.begin(),m_4Squares.end(),tmpSquares.begin(), tmp);
            setMaxMinXY(tmpSquares);
            if( (checkBounds(orgin,orgin) == true) && (isExist(tmpSquares) == false) )
            {
                std::copy(tmpSquares.begin(),tmpSquares.end(),m_4Squares.begin());
            }
            setMaxMinXY(m_4Squares);
        }

        const std::list<std::pair<T1,T2> >& getSquares()const
        {
            return m_4Squares;
        }
        const std::list<std::pair<T1,T2> >& getFallSquares()const
        {
            return m_fallSquares;
        }
    };
}
#endif //UNTITLED_MYSQUARE_H
