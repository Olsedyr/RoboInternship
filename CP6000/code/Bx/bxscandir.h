//bxscandir.h

struct bxdirent
{
       char d_name[_MAX_PATH];
       int  d_type; // 4 = dir, 8 = file
};

       
