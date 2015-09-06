##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=md5parse
ConfigurationName      :=Debug
WorkspacePath          := "F:\gits\graphics"
ProjectPath            := "F:\gits\graphics\md5parse"
IntermediateDirectory  :=E:/projects/builds/$(ProjectName)/Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Administrator
Date                   :=06/09/2015
CodeLitePath           :="E:\application\CodeLite"
LinkerName             :=E:/tdmgcc32/bin/g++.exe
SharedObjectLinkerName :=E:/tdmgcc32/bin/g++.exe -shared -fPIC
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
OutputFile             :=E:/projects/builds/$(ProjectName)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="md5parse.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=E:/tdmgcc32/bin/windres.exe
LinkOptions            :=  
IncludePath            := $(IncludeSwitch)E:/tdmgcclib/include  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                :=$(LibraryPathSwitch)E:/tdmgcclib/lib  $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := E:/tdmgcc32/bin/ar.exe rcu
CXX      := E:/tdmgcc32/bin/g++.exe
CC       := E:/tdmgcc32/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := E:/tdmgcc32/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=E:\application\CodeLite
BuildDir:=E:/projects/builds
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/buffer.cpp$(ObjectSuffix) $(IntermediateDirectory)/md5_md5.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "E:/projects/builds/$(ProjectName)/Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "E:/projects/builds/$(ProjectName)/Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/md5parse/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/buffer.cpp$(ObjectSuffix): buffer.cpp $(IntermediateDirectory)/buffer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/md5parse/buffer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/buffer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/buffer.cpp$(DependSuffix): buffer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/buffer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/buffer.cpp$(DependSuffix) -MM "buffer.cpp"

$(IntermediateDirectory)/buffer.cpp$(PreprocessSuffix): buffer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/buffer.cpp$(PreprocessSuffix) "buffer.cpp"

$(IntermediateDirectory)/md5_md5.cpp$(ObjectSuffix): md5/md5.cpp $(IntermediateDirectory)/md5_md5.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/md5parse/md5/md5.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/md5_md5.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/md5_md5.cpp$(DependSuffix): md5/md5.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/md5_md5.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/md5_md5.cpp$(DependSuffix) -MM "md5/md5.cpp"

$(IntermediateDirectory)/md5_md5.cpp$(PreprocessSuffix): md5/md5.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/md5_md5.cpp$(PreprocessSuffix) "md5/md5.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r E:/projects/builds/$(ProjectName)/Debug/


