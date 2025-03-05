/****************************************************************************
* Copyright (C) 2003 Thomas Noerby, MPN A/S.  All rights reserved.          *
*****************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "scene.h"
#include "cmd.h"

static tmpnScene Scene;
tmpnScene *scene=&Scene;

static int boneId=0;
static int GEID=0;
static int GDID=0;
static int GBID=0;
static int GCID=0;
static int GAID=0;
static tmpnMaterial redMaterial={{1.0f, 0.0, 0.0,1.0},{1.0f, 0.0, 0.0,1.0},{1.0f, 0.0, 0.0,1.0},1.0};
static tmpnMaterial floorMaterial={{0.6f, 0.6, 0.6, 1.0},{0.6f, 0.6, 0.6, 1.0},{0.0f, 0.0, 0.0, 1.0}, 1.0};
static tmpnMaterial woodMaterial={{1.0f, 1.0, 0.0,1.0},{1.0f, 1.0, 0.0,1.0},{0.0f, 0.0, 0.0,1.0},0.0};
static tmpnMaterial mpnMaterial={{0.0f, 0.545098f, 0.8f,0.75},{0.0f, 0.545098f, 0.8f,1.0},{0.0f, 0.545098f, 0.8f,1.0},127.0};
static tmpnMaterial armMaterial={ {0.9f, 0.9f, 0.9f,0.6},{0.9f, 0.9f, 0.9f,0.6},{0.2f, 0.2f, 0.2f,0.6},0.1};
static tmpnMaterial keyMaterial={ {10.0f, 10.0f, 10.0f,10.0},{10.0f, 10.0f, 10.0f,10.0},{10.0f, 10.0f, 10.0f,10.0},127.0};
static tmpnColor    currentmpnColor={1.0, 1.0, 1.0};
static tmpnMaterial currentmpnMaterial={{0.9, 0.0, 0.0, 1.0},{0.9, 0.0, 0.0, 1.0},{0.9, 0.0, 0.0, 1.0},1.0};

static void setmpnMaterial(tmpnMaterial m)
{
  currentmpnMaterial=m;
  currentmpnColor.r=m.ambient[0];
  currentmpnColor.g=m.ambient[1];
  currentmpnColor.b=m.ambient[2];
}

static void newBone(tmpnBone *bone,const char* name, float tx,float ty,float tz
            ,float lx, float ly,float lz, int cyl)
{
  bone->id = boneId++;
  bone->dim.x = lx;
  bone->dim.y = ly;
  bone->dim.z = lz;
  bone->cyl = cyl;
  bone->color.r = currentmpnColor.r;
  bone->color.g = currentmpnColor.g;
  bone->color.b = currentmpnColor.b;
  bone->material.diffuse[0]=1.2*currentmpnMaterial.diffuse[0];
  bone->material.diffuse[1]=1.2*currentmpnMaterial.diffuse[1];
  bone->material.diffuse[2]=1.2*currentmpnMaterial.diffuse[2];
  bone->material.diffuse[3]=1.0*currentmpnMaterial.diffuse[3];

  bone->material.ambient[0]=1.2*currentmpnMaterial.ambient[0];
  bone->material.ambient[1]=1.2*currentmpnMaterial.ambient[1];
  bone->material.ambient[2]=1.2*currentmpnMaterial.ambient[2];
  bone->material.ambient[3]=1.0*currentmpnMaterial.ambient[3];

  bone->material.specular[0]=0.2*currentmpnMaterial.specular[0];
  bone->material.specular[1]=0.2*currentmpnMaterial.specular[1];
  bone->material.specular[2]=0.2*currentmpnMaterial.specular[2];
  bone->material.specular[3]=1.0*currentmpnMaterial.specular[3];

  bone->material.shininess=0.2*currentmpnMaterial.shininess;
  strcpy(bone->name,name);
  bone->trans.x = tx;
  bone->trans.y = ty;
  bone->trans.z = tz;
  bone->gllist=0;
}

static void createRobotObjects(tmpnRobot *robot)
{
  boneId=1;
  setmpnMaterial(floorMaterial);
  newBone(&scene->floor,"Floor",-2000.0,-1500.0,-2000.0,3500.0,50.0,robot->m_gantryLength+700,BONE_BOX);
  setmpnMaterial(mpnMaterial);
  if(atoi(robot->m_name)<400||atoi(robot->m_name)>499)
  {
    newBone(&scene->foot  ,"Foot"  ,0.0,        0.0,0.0,GANTRY_WIDTH,FOOT_HEIGHT,FOOT_LENGTH ,BONE_BOX);
    newBone(&scene->leg   ,"Leg"   ,0.0,FOOT_HEIGHT,0.0,GANTRY_WIDTH,robot->m_legHeight, LEG_LENGTH,BONE_BOX);
    newBone(&scene->gantry,"Gantry",0.0,robot->m_legHeight ,0.0,GANTRY_WIDTH,GANTRY_HEIGHT,robot->m_gantryLength,BONE_BOX);
    //AAAAAAAAAAAA
    setmpnMaterial(redMaterial);
    newBone(&scene->gearA,"Gear A",0.0,0.0,0.0,0.0,0.0,0.0,BONE_BOX);
    GAID = scene->gearA.id;
    setmpnMaterial(armMaterial);
    newBone(&scene->shoulder,"Shoulder",    0.0,  GANTRY_HEIGHT, EMERGENCY_LENGTH
    ,SHOULDER_WIDTH,SHOULDER_HEIGHT,  SHOULDER_LENGTH,BONE_BOX);   //Shoulder pos on gear
    //BBBBBBBBBBBB
    setmpnMaterial(redMaterial);
    newBone(&scene->gearB,"Gear B"  ,  GANTRY_WIDTH*0.5,  robot->m_shoulderGearB-GANTRY_HEIGHT,SHOULDER_LENGTH
    ,GEAR_SIZE,       GEAR_SIZE,  GEAR_SIZE,BONE_BOX); //Gear position in shoulder
     scene->gearB.rot.z = 0.0;
    GBID = scene->gearB.id;
    setmpnMaterial(armMaterial);
    newBone(&scene->upperArm,"UpperArm",    0.0,    0.0,         0.0
    ,robot->m_Link[1].length,    UARM_SIZE,   UARM_SIZE,BONE_CYL);
    //CCCCCCCCCCC
     setmpnMaterial(redMaterial);
    newBone(&scene->gearC,"Gear C"  , robot->m_Link[1].length,    0.0,         0.0
    ,GEAR_SIZE,       GEAR_SIZE,  GEAR_SIZE,BONE_BOX);
    scene->gearC.rot.z = -90.0;
    GCID = scene->gearC.id;
    setmpnMaterial(armMaterial);
    newBone(&scene->lowerArm,"LowerArm",    0.0,    0.0,         0.0
    ,robot->m_Link[2].length,        LARM_SIZE,   LARM_SIZE*0.5,BONE_CYL);
    newBone(&scene->lowerArm2,"LowerArm2",robot->m_Link[2].length-150.0,    -70.0,         -100.0
    ,220.0                   ,              140.0,            200.0,BONE_BOX);
    //DDDDDDDDDDDDD
    setmpnMaterial(redMaterial);
    newBone(&scene->gearD,"Gear D"  , /*robot->m_Link[2].length*/150.0,    70.0,       100.0
    ,GEAR_SIZE,       GEAR_SIZE,  GEAR_SIZE,BONE_BOX);
    GDID = scene->gearD.id;
    setmpnMaterial(armMaterial);
    newBone(&scene->wrist,"Wrist"   ,    0.0,    0.0,         0.0
    ,robot->m_Link[3].length,        WRIST_SIZE*0.25,   WRIST_SIZE*0.5,BONE_CYL);
    //EEEEEEEEEEEEE
    setmpnMaterial(redMaterial);
    newBone(&scene->gearE,"Gear E"  , robot->m_Link[3].length,    0.0,         0.0
    ,GEAR_SIZE,       GEAR_SIZE,  GEAR_SIZE,BONE_BOX);
    scene->gearE.rot.z = 0.0;
    GEID = scene->gearE.id;
    setmpnMaterial(armMaterial);
    newBone(&scene->flange,"Flange"   ,  0.0,    0.0,         0.0
    ,0.0,        40.0,   40.0,BONE_CYL);
  }
  else
  {
    newBone(&scene->foot  ,"Foot"  ,0.0,  0.0,0.0,GANTRY_WIDTH1,FOOT_HEIGHT1,FOOT_LENGTH1 ,BONE_BOX);
    newBone(&scene->leg   ,"Leg"   ,0.0,FOOT_HEIGHT1,0.0,GANTRY_WIDTH1,robot->m_legHeight, LEG_LENGTH1,BONE_BOX);
    newBone(&scene->gantry,"Gantry",0.0,robot->m_legHeight ,0.0,GANTRY_WIDTH1,GANTRY_HEIGHT1,robot->m_gantryLength,BONE_BOX);
    //AAAAAAAAAAAA
    setmpnMaterial(redMaterial);
    newBone(&scene->gearA,"Gear A",0.0,0.0,0.0,0.0,0.0,0.0,BONE_BOX);
    GAID = scene->gearA.id;
    setmpnMaterial(armMaterial);
    newBone(&scene->shoulder,"Shoulder",    0.0,  GANTRY_HEIGHT1, EMERGENCY_LENGTH1
    ,SHOULDER_WIDTH1,SHOULDER_HEIGHT1,  SHOULDER_LENGTH1,BONE_BOX);   //Shoulder pos on gear
    //BBBBBBBBBBBB
    setmpnMaterial(redMaterial);
    newBone(&scene->gearB,"Gear B"  ,  GANTRY_WIDTH1*0.5,  robot->m_shoulderGearB-GANTRY_HEIGHT1,SHOULDER_LENGTH1
    ,GEAR_SIZE1,       GEAR_SIZE1,  GEAR_SIZE1,BONE_BOX); //Gear position in shoulder
     scene->gearB.rot.z = 0.0;
    GBID = scene->gearB.id;
    setmpnMaterial(armMaterial);
    newBone(&scene->upperArm,"UpperArm",    0.0,    0.0,         0.0
	    ,robot->m_Link[1].length,    UARM_SIZE1,   UARM_SIZE1,BONE_CYL);
    //CCCCCCCCCCC
     setmpnMaterial(redMaterial);
    newBone(&scene->gearC,"Gear C"  , robot->m_Link[1].length,    0.0,         0.0
    ,GEAR_SIZE,       GEAR_SIZE1,  GEAR_SIZE1,BONE_BOX);
    scene->gearC.rot.z = -90.0;
    GCID = scene->gearC.id;
    setmpnMaterial(armMaterial);
    newBone(&scene->lowerArm,"LowerArm",    0.0,    0.0,         0.0
    ,robot->m_Link[2].length,        LARM_SIZE1,   LARM_SIZE1*0.5,BONE_CYL);
    newBone(&scene->lowerArm2,"LowerArm2",robot->m_Link[2].length-150.0,    -70.0,         -100.0
    ,220.0                   ,              140.0,            200.0,BONE_BOX);
    //DDDDDDDDDDDDD
    setmpnMaterial(redMaterial);
    newBone(&scene->gearD,"Gear D"  , /*robot->m_Link[2].length*/150.0,    70.0,       100.0
    ,GEAR_SIZE1,       GEAR_SIZE1,  GEAR_SIZE1,BONE_BOX);
    GDID = scene->gearD.id;
    setmpnMaterial(armMaterial);
    newBone(&scene->wrist,"Wrist"   ,    0.0,    0.0,         0.0
    ,robot->m_Link[3].length,        WRIST_SIZE1*0.25,   WRIST_SIZE1*0.5,BONE_CYL);
    //EEEEEEEEEEEEE
    setmpnMaterial(redMaterial);
    newBone(&scene->gearE,"Gear E"  , robot->m_Link[3].length,    0.0,         0.0
    ,GEAR_SIZE,       GEAR_SIZE1,  GEAR_SIZE1,BONE_BOX);
    scene->gearE.rot.z = 0.0;
    GEID = scene->gearE.id;
    setmpnMaterial(armMaterial);
    newBone(&scene->flange,"Flange"   ,  0.0,    0.0,         0.0
    ,0.0,        40.0,   40.0,BONE_CYL);
  }
}
 
void loadScene(tmpnWorkcell *workcell)
{
  int l,b;
  boneId=1;
  createRobotObjects(&workcell->robots.robot[0]);
  //TOOL OBJECT
  setmpnMaterial(armMaterial);
  newBone(&scene->tool,"Tool"    , 0.0,    0.0,         0.0
  ,0.0,       0.0,  0.0,BONE_BOX);

  //ITEM OBJECT
  setmpnMaterial(woodMaterial);
  newBone(&scene->pallet,"Pallet"  ,  0.0,   -150.0,      0.0
  ,1200.0,       150.0,  800.0,BONE_BOX);

  setmpnMaterial(keyMaterial);
  newBone(&scene->key,"Key",0.0,0.0,0.0,20.0,20.0,20.0,BONE_BOX);

  for(l=0;l<workcell->accessories.maxidx;l++)
  {
    setmpnMaterial(workcell->accessories.accessory[l].material);
    newBone(&scene->accessories.accessory[l],"Accessory"
    ,workcell->accessories.accessory[l].transformation.x
    ,workcell->accessories.accessory[l].transformation.y
    ,workcell->accessories.accessory[l].transformation.z
    ,workcell->accessories.accessory[l].dimention.x
    ,workcell->accessories.accessory[l].dimention.y
    ,workcell->accessories.accessory[l].dimention.z
    ,BONE_BOX);
  }
  scene->accessories.maxidx=workcell->accessories.maxidx;
  scene->boxpicked=FALSE;
  for(l=0;l<10;l++)
  {
    for(b=0;b<4;b++) //altid 4 pr lag
    {
      scene->palletAboxPlaced[l][b]=TRUE;
    }
  }
}
