#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=mpicxx
CXX=mpicxx
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/7e3bde50/BestFeatureMsg.o \
	${OBJECTDIR}/_ext/7e3bde50/Cell.o \
	${OBJECTDIR}/_ext/7e3bde50/CellBPC.o \
	${OBJECTDIR}/_ext/7e3bde50/Collection.o \
	${OBJECTDIR}/_ext/7e3bde50/DepthImage.o \
	${OBJECTDIR}/_ext/7e3bde50/DistributionManager.o \
	${OBJECTDIR}/_ext/7e3bde50/Estructura.o \
	${OBJECTDIR}/_ext/7e3bde50/Features.o \
	${OBJECTDIR}/_ext/7e3bde50/FeaturesMat.o \
	${OBJECTDIR}/_ext/7e3bde50/ForestManager.o \
	${OBJECTDIR}/_ext/7e3bde50/Image.o \
	${OBJECTDIR}/_ext/7e3bde50/ImageDispatcher.o \
	${OBJECTDIR}/_ext/7e3bde50/ImageGetter.o \
	${OBJECTDIR}/_ext/7e3bde50/ImageManager.o \
	${OBJECTDIR}/_ext/7e3bde50/ImageOperations.o \
	${OBJECTDIR}/_ext/7e3bde50/LabelImage.o \
	${OBJECTDIR}/_ext/7e3bde50/Node.o \
	${OBJECTDIR}/_ext/7e3bde50/NodeResource.o \
	${OBJECTDIR}/_ext/7e3bde50/NodeResult.o \
	${OBJECTDIR}/_ext/7e3bde50/NodeTrainee.o \
	${OBJECTDIR}/_ext/7e3bde50/PointsSelect.o \
	${OBJECTDIR}/_ext/7e3bde50/QueueTask.o \
	${OBJECTDIR}/_ext/7e3bde50/QueueThread.o \
	${OBJECTDIR}/_ext/7e3bde50/Resource.o \
	${OBJECTDIR}/_ext/7e3bde50/Resources.o \
	${OBJECTDIR}/_ext/7e3bde50/Scheduler.o \
	${OBJECTDIR}/_ext/7e3bde50/StrategyImage.o \
	${OBJECTDIR}/_ext/7e3bde50/Task.o \
	${OBJECTDIR}/_ext/7e3bde50/TrainManager.o \
	${OBJECTDIR}/_ext/7e3bde50/Trainer.o \
	${OBJECTDIR}/_ext/7e3bde50/TrainerBPC.o \
	${OBJECTDIR}/_ext/7e3bde50/TrainingJob.o \
	${OBJECTDIR}/ConfigData.o \
	${OBJECTDIR}/Initializator.o \
	${OBJECTDIR}/configValidator.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/userValidator.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-fopenmp
CXXFLAGS=-fopenmp

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/usr/local/lib -L/usr/local/include -L${MPI_INCLUDE_PATH} -L${Boost_INCLUDE_DIRS} -L${USER_INCLUDE_PATH} -L/opt/local/include -lboost_serialization -lcluster-delegator -lboost_mpi `pkg-config --libs opencv`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/distributedtrees

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/distributedtrees: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/distributedtrees ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/7e3bde50/BestFeatureMsg.o: /home/gabo/Documents/DistributedTrees/BestFeatureMsg.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e3bde50
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e3bde50/BestFeatureMsg.o /home/gabo/Documents/DistributedTrees/BestFeatureMsg.cpp

${OBJECTDIR}/_ext/7e3bde50/Cell.o: /home/gabo/Documents/DistributedTrees/Cell.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e3bde50
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e3bde50/Cell.o /home/gabo/Documents/DistributedTrees/Cell.cpp

${OBJECTDIR}/_ext/7e3bde50/CellBPC.o: /home/gabo/Documents/DistributedTrees/CellBPC.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e3bde50
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e3bde50/CellBPC.o /home/gabo/Documents/DistributedTrees/CellBPC.cpp

${OBJECTDIR}/_ext/7e3bde50/Collection.o: /home/gabo/Documents/DistributedTrees/Collection.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e3bde50
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e3bde50/Collection.o /home/gabo/Documents/DistributedTrees/Collection.cpp

${OBJECTDIR}/_ext/7e3bde50/DepthImage.o: /home/gabo/Documents/DistributedTrees/DepthImage.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e3bde50
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e3bde50/DepthImage.o /home/gabo/Documents/DistributedTrees/DepthImage.cpp

${OBJECTDIR}/_ext/7e3bde50/DistributionManager.o: /home/gabo/Documents/DistributedTrees/DistributionManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e3bde50
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e3bde50/DistributionManager.o /home/gabo/Documents/DistributedTrees/DistributionManager.cpp

${OBJECTDIR}/_ext/7e3bde50/Estructura.o: /home/gabo/Documents/DistributedTrees/Estructura.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e3bde50
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e3bde50/Estructura.o /home/gabo/Documents/DistributedTrees/Estructura.cpp

${OBJECTDIR}/_ext/7e3bde50/Features.o: /home/gabo/Documents/DistributedTrees/Features.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e3bde50
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e3bde50/Features.o /home/gabo/Documents/DistributedTrees/Features.cpp

${OBJECTDIR}/_ext/7e3bde50/FeaturesMat.o: /home/gabo/Documents/DistributedTrees/FeaturesMat.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e3bde50
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e3bde50/FeaturesMat.o /home/gabo/Documents/DistributedTrees/FeaturesMat.cpp

${OBJECTDIR}/_ext/7e3bde50/ForestManager.o: /home/gabo/Documents/DistributedTrees/ForestManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e3bde50
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e3bde50/ForestManager.o /home/gabo/Documents/DistributedTrees/ForestManager.cpp

${OBJECTDIR}/_ext/7e3bde50/Image.o: /home/gabo/Documents/DistributedTrees/Image.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e3bde50
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e3bde50/Image.o /home/gabo/Documents/DistributedTrees/Image.cpp

${OBJECTDIR}/_ext/7e3bde50/ImageDispatcher.o: /home/gabo/Documents/DistributedTrees/ImageDispatcher.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e3bde50
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e3bde50/ImageDispatcher.o /home/gabo/Documents/DistributedTrees/ImageDispatcher.cpp

${OBJECTDIR}/_ext/7e3bde50/ImageGetter.o: /home/gabo/Documents/DistributedTrees/ImageGetter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e3bde50
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e3bde50/ImageGetter.o /home/gabo/Documents/DistributedTrees/ImageGetter.cpp

${OBJECTDIR}/_ext/7e3bde50/ImageManager.o: /home/gabo/Documents/DistributedTrees/ImageManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e3bde50
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e3bde50/ImageManager.o /home/gabo/Documents/DistributedTrees/ImageManager.cpp

${OBJECTDIR}/_ext/7e3bde50/ImageOperations.o: /home/gabo/Documents/DistributedTrees/ImageOperations.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e3bde50
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e3bde50/ImageOperations.o /home/gabo/Documents/DistributedTrees/ImageOperations.cpp

${OBJECTDIR}/_ext/7e3bde50/LabelImage.o: /home/gabo/Documents/DistributedTrees/LabelImage.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e3bde50
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e3bde50/LabelImage.o /home/gabo/Documents/DistributedTrees/LabelImage.cpp

${OBJECTDIR}/_ext/7e3bde50/Node.o: /home/gabo/Documents/DistributedTrees/Node.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e3bde50
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e3bde50/Node.o /home/gabo/Documents/DistributedTrees/Node.cpp

${OBJECTDIR}/_ext/7e3bde50/NodeResource.o: /home/gabo/Documents/DistributedTrees/NodeResource.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e3bde50
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e3bde50/NodeResource.o /home/gabo/Documents/DistributedTrees/NodeResource.cpp

${OBJECTDIR}/_ext/7e3bde50/NodeResult.o: /home/gabo/Documents/DistributedTrees/NodeResult.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e3bde50
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e3bde50/NodeResult.o /home/gabo/Documents/DistributedTrees/NodeResult.cpp

${OBJECTDIR}/_ext/7e3bde50/NodeTrainee.o: /home/gabo/Documents/DistributedTrees/NodeTrainee.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e3bde50
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e3bde50/NodeTrainee.o /home/gabo/Documents/DistributedTrees/NodeTrainee.cpp

${OBJECTDIR}/_ext/7e3bde50/PointsSelect.o: /home/gabo/Documents/DistributedTrees/PointsSelect.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e3bde50
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e3bde50/PointsSelect.o /home/gabo/Documents/DistributedTrees/PointsSelect.cpp

${OBJECTDIR}/_ext/7e3bde50/QueueTask.o: /home/gabo/Documents/DistributedTrees/QueueTask.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e3bde50
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e3bde50/QueueTask.o /home/gabo/Documents/DistributedTrees/QueueTask.cpp

${OBJECTDIR}/_ext/7e3bde50/QueueThread.o: /home/gabo/Documents/DistributedTrees/QueueThread.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e3bde50
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e3bde50/QueueThread.o /home/gabo/Documents/DistributedTrees/QueueThread.cpp

${OBJECTDIR}/_ext/7e3bde50/Resource.o: /home/gabo/Documents/DistributedTrees/Resource.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e3bde50
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e3bde50/Resource.o /home/gabo/Documents/DistributedTrees/Resource.cpp

${OBJECTDIR}/_ext/7e3bde50/Resources.o: /home/gabo/Documents/DistributedTrees/Resources.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e3bde50
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e3bde50/Resources.o /home/gabo/Documents/DistributedTrees/Resources.cpp

${OBJECTDIR}/_ext/7e3bde50/Scheduler.o: /home/gabo/Documents/DistributedTrees/Scheduler.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e3bde50
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e3bde50/Scheduler.o /home/gabo/Documents/DistributedTrees/Scheduler.cpp

${OBJECTDIR}/_ext/7e3bde50/StrategyImage.o: /home/gabo/Documents/DistributedTrees/StrategyImage.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e3bde50
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e3bde50/StrategyImage.o /home/gabo/Documents/DistributedTrees/StrategyImage.cpp

${OBJECTDIR}/_ext/7e3bde50/Task.o: /home/gabo/Documents/DistributedTrees/Task.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e3bde50
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e3bde50/Task.o /home/gabo/Documents/DistributedTrees/Task.cpp

${OBJECTDIR}/_ext/7e3bde50/TrainManager.o: /home/gabo/Documents/DistributedTrees/TrainManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e3bde50
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e3bde50/TrainManager.o /home/gabo/Documents/DistributedTrees/TrainManager.cpp

${OBJECTDIR}/_ext/7e3bde50/Trainer.o: /home/gabo/Documents/DistributedTrees/Trainer.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e3bde50
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e3bde50/Trainer.o /home/gabo/Documents/DistributedTrees/Trainer.cpp

${OBJECTDIR}/_ext/7e3bde50/TrainerBPC.o: /home/gabo/Documents/DistributedTrees/TrainerBPC.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e3bde50
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e3bde50/TrainerBPC.o /home/gabo/Documents/DistributedTrees/TrainerBPC.cpp

${OBJECTDIR}/_ext/7e3bde50/TrainingJob.o: /home/gabo/Documents/DistributedTrees/TrainingJob.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/7e3bde50
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7e3bde50/TrainingJob.o /home/gabo/Documents/DistributedTrees/TrainingJob.cpp

${OBJECTDIR}/ConfigData.o: ConfigData.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ConfigData.o ConfigData.cpp

${OBJECTDIR}/Initializator.o: Initializator.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Initializator.o Initializator.cpp

${OBJECTDIR}/configValidator.o: configValidator.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/configValidator.o configValidator.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/userValidator.o: userValidator.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -s `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/userValidator.o userValidator.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/distributedtrees

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
