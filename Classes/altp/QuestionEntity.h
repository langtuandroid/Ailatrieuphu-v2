//
//  QuestionEntity.h
//  GMFramework
//
//  Created by langtujava on 4/23/14.
// Question
//

#ifndef __GMFramework__QuestionEntity__
#define __GMFramework__QuestionEntity__

#include "gmg.h"

static const string level = "Level";
static const string question = "Question";
static const string caseA = "CaseA";
static const string caseB = "CaseB";
static const string caseC = "CaseC";
static const string caseD = "CaseD";
static const string truecase = "TrueCase";
class QuestionEntity : public  BaseEntity
{

    GMF_CREATE_FUNC(QuestionEntity);
    GMF_SYNTHESIZE(level, Level);
    GMF_SYNTHESIZE(question, Question);
    GMF_SYNTHESIZE(caseA, CaseA);
    GMF_SYNTHESIZE(caseB, CaseB);
    GMF_SYNTHESIZE(caseC, CaseC);
    GMF_SYNTHESIZE(caseD, CaseD);
    GMF_SYNTHESIZE(truecase, TrueCase);

};



#endif /* defined(__GMFramework__QuestionEntity__) */
