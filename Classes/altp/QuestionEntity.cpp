//
//  QuestionEntity.cpp
//  GMFramework
//
//  Created by langtujava on 4/23/14.
//
//

#include "QuestionEntity.h"


const string QuestionEntity::tableName="Question";
const string QuestionEntity::dbFile="db";
const string QuestionEntity::sqlScriptFile="db";
const string QuestionEntity::sqlCreateTable=level + " nvarchar(5),"+question +" nvarchar(2000) ,"+caseA + " nvarchar(500),"+caseB +" nvarchar(500)," +caseC + " nvarchar(500),"+ caseD + " nvarchar(500),"+truecase +" nvarchar(1) ";