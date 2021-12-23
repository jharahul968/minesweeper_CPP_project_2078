#pragma once
class Global
{
    static int  glob_board_size, glob_total_mines;
    static bool flag1;
public:

    static inline void setglob_board_size (int bsize)
    {
        glob_board_size = bsize;
    }
    static inline int getglob_board_size ()
    {
        return (glob_board_size);
    }
    static inline void setglob_total_mines (int tot_mines)
    {
        glob_total_mines = tot_mines;
    }
    static inline int getglob_total_mines ()
    {
        return (glob_total_mines);
    }
    static inline void setflag1 (bool flg1)
    {
        flag1 = flg1;
    }
    static inline bool getflag1 ()
    {
        return (flag1);
    }
    static inline bool validityChecker (int a, int b)
    {
        return ((a < glob_board_size) && (b< glob_board_size) && a>=0 && b >=0);
    }

};




