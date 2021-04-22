##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=one3
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/am/Project_codelite/one3
ProjectPath            :=/home/am/Project_codelite/one3/one3
IntermediateDirectory  :=../build-$(ConfigurationName)/one3
OutDir                 :=../build-$(ConfigurationName)/one3
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=am
Date                   :=12/19/20
CodeLitePath           :=/home/am/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  -lfl 
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -w  -Wno-psabi  $(Preprocessors)
CFLAGS   :=  -g -O0 -w  -Wno-psabi  $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=../build-$(ConfigurationName)/one3/print.c$(ObjectSuffix) ../build-$(ConfigurationName)/one3/one.c$(ObjectSuffix) ../build-$(ConfigurationName)/one3/parser.tab.c$(ObjectSuffix) ../build-$(ConfigurationName)/one3/lex.yy.c$(ObjectSuffix) ../build-$(ConfigurationName)/one3/ast.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/one3/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/one3"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/one3"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/one3/.d:
	@mkdir -p "../build-$(ConfigurationName)/one3"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/one3/print.c$(ObjectSuffix): print.c ../build-$(ConfigurationName)/one3/print.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/am/Project_codelite/one3/one3/print.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/print.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/one3/print.c$(DependSuffix): print.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/one3/print.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/one3/print.c$(DependSuffix) -MM print.c

../build-$(ConfigurationName)/one3/print.c$(PreprocessSuffix): print.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/one3/print.c$(PreprocessSuffix) print.c

../build-$(ConfigurationName)/one3/one.c$(ObjectSuffix): one.c ../build-$(ConfigurationName)/one3/one.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/am/Project_codelite/one3/one3/one.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/one.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/one3/one.c$(DependSuffix): one.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/one3/one.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/one3/one.c$(DependSuffix) -MM one.c

../build-$(ConfigurationName)/one3/one.c$(PreprocessSuffix): one.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/one3/one.c$(PreprocessSuffix) one.c

../build-$(ConfigurationName)/one3/parser.tab.c$(ObjectSuffix): parser.tab.c ../build-$(ConfigurationName)/one3/parser.tab.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/am/Project_codelite/one3/one3/parser.tab.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/parser.tab.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/one3/parser.tab.c$(DependSuffix): parser.tab.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/one3/parser.tab.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/one3/parser.tab.c$(DependSuffix) -MM parser.tab.c

../build-$(ConfigurationName)/one3/parser.tab.c$(PreprocessSuffix): parser.tab.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/one3/parser.tab.c$(PreprocessSuffix) parser.tab.c

../build-$(ConfigurationName)/one3/lex.yy.c$(ObjectSuffix): lex.yy.c ../build-$(ConfigurationName)/one3/lex.yy.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/am/Project_codelite/one3/one3/lex.yy.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lex.yy.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/one3/lex.yy.c$(DependSuffix): lex.yy.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/one3/lex.yy.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/one3/lex.yy.c$(DependSuffix) -MM lex.yy.c

../build-$(ConfigurationName)/one3/lex.yy.c$(PreprocessSuffix): lex.yy.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/one3/lex.yy.c$(PreprocessSuffix) lex.yy.c

../build-$(ConfigurationName)/one3/ast.c$(ObjectSuffix): ast.c ../build-$(ConfigurationName)/one3/ast.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/am/Project_codelite/one3/one3/ast.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ast.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/one3/ast.c$(DependSuffix): ast.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/one3/ast.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/one3/ast.c$(DependSuffix) -MM ast.c

../build-$(ConfigurationName)/one3/ast.c$(PreprocessSuffix): ast.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/one3/ast.c$(PreprocessSuffix) ast.c


-include ../build-$(ConfigurationName)/one3//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


