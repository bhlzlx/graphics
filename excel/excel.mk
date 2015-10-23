##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=excel
ConfigurationName      :=Debug
WorkspacePath          := "F:\gits\graphics"
ProjectPath            := "F:\gits\graphics\excel"
IntermediateDirectory  :=$(BuildDir)/$(ProjectName)/Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Administrator
Date                   :=23/10/2015
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
OutputFile             :=$(BuildDir)/$(ProjectName)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="excel.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=E:/tdmgcc32/bin/windres.exe
LinkOptions            :=  -liconv -pg 
IncludePath            := $(IncludeSwitch)E:/tdmgcclib/include $(IncludeSwitch)E:/tdmgcclib/include/freetype $(IncludeSwitch)F:/opengl/wxWidgets-3.0.2/include $(IncludeSwitch)F:/opengl/wxWidgets-3.0.2  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)../ow $(IncludeSwitch)./ow 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                :=$(LibraryPathSwitch)E:/tdmgcclib/lib $(LibraryPathSwitch)F:/opengl/wxWidgets-3.0.2/lib  $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := E:/tdmgcc32/bin/ar.exe rcu
CXX      := E:/tdmgcc32/bin/g++.exe
CC       := E:/tdmgcc32/bin/gcc.exe
CXXFLAGS :=  -g -pg -O0 -Wall -std=gnu++0x $(Preprocessors)
CFLAGS   :=  -g -pg -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := E:/tdmgcc32/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=E:\application\CodeLite
BuildDir:=E:/projects/builds
WXWIN:=G:/wxwidgets
WXCFG:=gcc_lib/mswud
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/owcmn_EncodeCommon.cpp$(ObjectSuffix) $(IntermediateDirectory)/owcmn_owcmn.cpp$(ObjectSuffix) $(IntermediateDirectory)/algorithm_md5.cpp$(ObjectSuffix) $(IntermediateDirectory)/buffer_buffer.cpp$(ObjectSuffix) $(IntermediateDirectory)/memory_memory.cpp$(ObjectSuffix) $(IntermediateDirectory)/owfile_owfile.cpp$(ObjectSuffix) $(IntermediateDirectory)/excel_excel.cpp$(ObjectSuffix) $(IntermediateDirectory)/excel_excel_def_imp.cpp$(ObjectSuffix) 



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
	@$(MakeDirCommand) "$(BuildDir)/$(ProjectName)/Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "$(BuildDir)/$(ProjectName)/Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/excel/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/owcmn_EncodeCommon.cpp$(ObjectSuffix): ../ow/owcmn/EncodeCommon.cpp $(IntermediateDirectory)/owcmn_EncodeCommon.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/ow/owcmn/EncodeCommon.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/owcmn_EncodeCommon.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/owcmn_EncodeCommon.cpp$(DependSuffix): ../ow/owcmn/EncodeCommon.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/owcmn_EncodeCommon.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/owcmn_EncodeCommon.cpp$(DependSuffix) -MM "../ow/owcmn/EncodeCommon.cpp"

$(IntermediateDirectory)/owcmn_EncodeCommon.cpp$(PreprocessSuffix): ../ow/owcmn/EncodeCommon.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/owcmn_EncodeCommon.cpp$(PreprocessSuffix) "../ow/owcmn/EncodeCommon.cpp"

$(IntermediateDirectory)/owcmn_owcmn.cpp$(ObjectSuffix): ../ow/owcmn/owcmn.cpp $(IntermediateDirectory)/owcmn_owcmn.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/ow/owcmn/owcmn.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/owcmn_owcmn.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/owcmn_owcmn.cpp$(DependSuffix): ../ow/owcmn/owcmn.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/owcmn_owcmn.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/owcmn_owcmn.cpp$(DependSuffix) -MM "../ow/owcmn/owcmn.cpp"

$(IntermediateDirectory)/owcmn_owcmn.cpp$(PreprocessSuffix): ../ow/owcmn/owcmn.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/owcmn_owcmn.cpp$(PreprocessSuffix) "../ow/owcmn/owcmn.cpp"

$(IntermediateDirectory)/algorithm_md5.cpp$(ObjectSuffix): ../ow/algorithm/md5.cpp $(IntermediateDirectory)/algorithm_md5.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/ow/algorithm/md5.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/algorithm_md5.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/algorithm_md5.cpp$(DependSuffix): ../ow/algorithm/md5.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/algorithm_md5.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/algorithm_md5.cpp$(DependSuffix) -MM "../ow/algorithm/md5.cpp"

$(IntermediateDirectory)/algorithm_md5.cpp$(PreprocessSuffix): ../ow/algorithm/md5.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/algorithm_md5.cpp$(PreprocessSuffix) "../ow/algorithm/md5.cpp"

$(IntermediateDirectory)/buffer_buffer.cpp$(ObjectSuffix): ../ow/buffer/buffer.cpp $(IntermediateDirectory)/buffer_buffer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/ow/buffer/buffer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/buffer_buffer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/buffer_buffer.cpp$(DependSuffix): ../ow/buffer/buffer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/buffer_buffer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/buffer_buffer.cpp$(DependSuffix) -MM "../ow/buffer/buffer.cpp"

$(IntermediateDirectory)/buffer_buffer.cpp$(PreprocessSuffix): ../ow/buffer/buffer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/buffer_buffer.cpp$(PreprocessSuffix) "../ow/buffer/buffer.cpp"

$(IntermediateDirectory)/memory_memory.cpp$(ObjectSuffix): ../ow/memory/memory.cpp $(IntermediateDirectory)/memory_memory.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/ow/memory/memory.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/memory_memory.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/memory_memory.cpp$(DependSuffix): ../ow/memory/memory.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/memory_memory.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/memory_memory.cpp$(DependSuffix) -MM "../ow/memory/memory.cpp"

$(IntermediateDirectory)/memory_memory.cpp$(PreprocessSuffix): ../ow/memory/memory.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/memory_memory.cpp$(PreprocessSuffix) "../ow/memory/memory.cpp"

$(IntermediateDirectory)/owfile_owfile.cpp$(ObjectSuffix): ../ow/owfile/owfile.cpp $(IntermediateDirectory)/owfile_owfile.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/ow/owfile/owfile.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/owfile_owfile.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/owfile_owfile.cpp$(DependSuffix): ../ow/owfile/owfile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/owfile_owfile.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/owfile_owfile.cpp$(DependSuffix) -MM "../ow/owfile/owfile.cpp"

$(IntermediateDirectory)/owfile_owfile.cpp$(PreprocessSuffix): ../ow/owfile/owfile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/owfile_owfile.cpp$(PreprocessSuffix) "../ow/owfile/owfile.cpp"

$(IntermediateDirectory)/excel_excel.cpp$(ObjectSuffix): ow/excel/excel.cpp $(IntermediateDirectory)/excel_excel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/excel/ow/excel/excel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/excel_excel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/excel_excel.cpp$(DependSuffix): ow/excel/excel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/excel_excel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/excel_excel.cpp$(DependSuffix) -MM "ow/excel/excel.cpp"

$(IntermediateDirectory)/excel_excel.cpp$(PreprocessSuffix): ow/excel/excel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/excel_excel.cpp$(PreprocessSuffix) "ow/excel/excel.cpp"

$(IntermediateDirectory)/excel_excel_def_imp.cpp$(ObjectSuffix): ow/excel/excel_def_imp.cpp $(IntermediateDirectory)/excel_excel_def_imp.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/excel/ow/excel/excel_def_imp.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/excel_excel_def_imp.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/excel_excel_def_imp.cpp$(DependSuffix): ow/excel/excel_def_imp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/excel_excel_def_imp.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/excel_excel_def_imp.cpp$(DependSuffix) -MM "ow/excel/excel_def_imp.cpp"

$(IntermediateDirectory)/excel_excel_def_imp.cpp$(PreprocessSuffix): ow/excel/excel_def_imp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/excel_excel_def_imp.cpp$(PreprocessSuffix) "ow/excel/excel_def_imp.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(BuildDir)/$(ProjectName)/Debug/


