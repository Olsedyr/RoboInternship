#define DIOC_START_CYCLUS      1

#define ISLAND_COM_STATUS 5357
#define ERROR_REPORTING   5358
#define NODE_CONF         5359
#define NODE_ASSEM        5367
#define EMRG_MSG          5375
#define FAULT_DETECT      5383
#define NIP_STATUS        5391

#define OUTPUT_PM         1 // output base for kassemagasin
#define OUTPUT_PK_1       4 // output base for kaedetransport
#define OUTPUT_PK_2       5 // output base for kaedetransport
#define OUTPUT_PK_3       2 // output base for pallekryds lift
#define INPUT_PM          5392
#define INPUT_PM_1        4 //PM_REED_TOP, PM_REED_BOTTOM
#define INPUT_PM_2        6 // PM_REED_MID_L, PM_REED_MID_R, PM_REED_GRIB, PM_REED_SLIP
#define INPUT_PM_3        14 // FOTO_PALLE_NEDE
#define INPUT_PB_1        0 // fotocell for PB
#define INPUT_CV_1        1 // fotocell for PB


#define PM_FOTO_PALLE_NEDE  0x01
#define PM_FOTO_PALLE_KLAR  0x02
#define PM_REED_TOP         0x04
#define PM_REED_MID_L       0x01
#define PM_REED_MID_R       0x02
#define PM_REED_BOTTOM      0x08
#define PM_REED_GRIB        0x04
#define PM_REED_SLIP        0x08

#define PM_CYL_UP_L         0x01
#define PM_CYL_DOWN_L       0x02
#define PM_CYL_UP_R         0x04
#define PM_CYL_DOWN_R       0x08
#define PM_CYLGRIB_GRIB     0x10
#define PM_CYLGRIB_SLIP     0x20

#define PM_IDLE             0
#define PM_STARTUP_1        1
#define PM_STARTUP_2        2
#define PM_STARTUP_3        3
#define PM_CYL_BOTTOM       4
#define PM_CYL_UP_MID       5
#define PM_GRIB_LIFT        6
#define PM_CYL_TOP          7
#define PM_PALLET_READY     8
#define PM_RELEASE          9
#define PM_LOAD_NEW_PALLETS       10
#define PM_LOAD_NEW_PALLETS_TIMEOUT       11
#define PM_WAITING_FOR_PALLET     12
#define PM_PALLET_MOVE_TO_MID_POS 13
#define PM_PALLET_READY_IN_MID    14
#define PM_PALLET_READY_TIMEOUT   15
#define STM_TIMER           9999
#define PM_DEAD             999

#define PB_SECTOR_1             0x01
#define PB_SECTOR_2             0x02
#define PB_SECTOR_SIDE          0x04
#define PB_SECTOR_3             0x08

#define PB_OUT_SECTOR_1          0x01 //OUTPUT_PK_2
#define PB_OUT_SECTOR_2          0x40 //OUTPUT_PK_1
#define PK_OUT_SECTOR_3_REV      0x02 //OUTPUT_PK_1
#define PK_OUT_SECTOR_3_FWD      0x01 //OUTPUT_PK_1
#define PK_OUT_SECTOR_3_LIFT     0x08 //OUTPUT_PK_3
#define PM_OUT_CHAIN             0x04 //OUTPUT_PK_1
#define PK_OUT_CHAIN             0x10 //
#define CV_OUT_CONV_INFEED       0x10 //OUTPUT_PK_2
#define CV_OUT_CONV_SACK         0x40 //OUTPUT_PK_2

#define PB_PALLET_READY         1
#define PB_PALLET_MISSING       2
#define PB_WAITING_FOR_PALLET   3

#define PK_IDLE                 0
#define PK_PALLET_READY         1
#define PK_PALLET_MISSING       2
#define PK_PALLET_REV           3
#define PK_PALLET_REV_TIMEOUT    4
#define PK_START_CYCLUS          5
#define PK_PALLET_FWD           6
#define PK_GET_NEW_PALLET        7
#define PK_PALLET_SIDE_ALIGN    8
#define PK_PALLET_SIDE_ALIGN_TIMEOUT 9
#define PK_LOWER_SECTOR_3            10
#define PK_LIFT_SECTOR_3            11
#define PK_LIFT_SECTOR_3_TIMEOUT    12
#define PK_LOWER_SECTOR_3_TIMEOUT   13

#define CV1_FOTO_1             0x04

#define CV_IDLE                 0
#define CV_GET_BAG_READY         1
#define CV_WAIT_BAG_READY        2
#define CV_BAG_READY            3
#define CV_MOVE_BAG              4
#define CV_WAIT_FOR_BAG_MOVED   5

#define TIMOUT_FOR_PALLET_DISPENSER 1000000
#define TIMOUT_FOR_PALLET_LOAD      10000000
#define TIMOUT_FOR_PALLET_REV       1000000
#define TIMOUT_FOR_PALLET_SIDE_ALIGN 5000000
#define TIMOUT_FOR_LOWER_SECTOR_3   1000000
#define TIMOUT_FOR_MISSING_PALLET_TEST 3000000

extern volatile short idata[25];
extern volatile short odata[10];
