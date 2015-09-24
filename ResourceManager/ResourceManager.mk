##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=ResourceManager
ConfigurationName      :=Debug
WorkspacePath          := "F:\gits\graphics"
ProjectPath            := "F:\gits\graphics\ResourceManager"
IntermediateDirectory  :=$(BuildDir)/$(ProjectName)/Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Administrator
Date                   :=24/09/2015
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
ObjectsFileList        :="ResourceManager.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=E:/tdmgcc32/bin/windres.exe
LinkOptions            :=  -lz -lgdi32 -luser32 -lkernel32
IncludePath            := $(IncludeSwitch)E:/tdmgcclib/include $(IncludeSwitch)E:/tdmgcclib/include/freetype $(IncludeSwitch)F:/opengl/wxWidgets-3.0.2/include $(IncludeSwitch)F:/opengl/wxWidgets-3.0.2  $(IncludeSwitch). $(IncludeSwitch). 
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
CXXFLAGS :=  -g -O0 -Wall -std=c++11 $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := E:/tdmgcc32/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=E:\application\CodeLite
BuildDir:=E:/projects/builds
WXWIN:=G:/wxwidgets
WXCFG:=gcc_lib/mswud
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/buffer_buffer.cpp$(ObjectSuffix) $(IntermediateDirectory)/owfile_owfile.cpp$(ObjectSuffix) $(IntermediateDirectory)/owZip_owZip.cpp$(ObjectSuffix) $(IntermediateDirectory)/algorithm_md5.cpp$(ObjectSuffix) $(IntermediateDirectory)/package_owPackage.cpp$(ObjectSuffix) $(IntermediateDirectory)/package_package_common.cpp$(ObjectSuffix) 



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
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/ResourceManager/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/buffer_buffer.cpp$(ObjectSuffix): buffer/buffer.cpp $(IntermediateDirectory)/buffer_buffer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/ResourceManager/buffer/buffer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/buffer_buffer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/buffer_buffer.cpp$(DependSuffix): buffer/buffer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/buffer_buffer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/buffer_buffer.cpp$(DependSuffix) -MM "buffer/buffer.cpp"

$(IntermediateDirectory)/buffer_buffer.cpp$(PreprocessSuffix): buffer/buffer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/buffer_buffer.cpp$(PreprocessSuffix) "buffer/buffer.cpp"

$(IntermediateDirectory)/owfile_owfile.cpp$(ObjectSuffix): owfile/owfile.cpp $(IntermediateDirectory)/owfile_owfile.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/ResourceManager/owfile/owfile.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/owfile_owfile.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/owfile_owfile.cpp$(DependSuffix): owfile/owfile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/owfile_owfile.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/owfile_owfile.cpp$(DependSuffix) -MM "owfile/owfile.cpp"

$(IntermediateDirectory)/owfile_owfile.cpp$(PreprocessSuffix): owfile/owfile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/owfile_owfile.cpp$(PreprocessSuffix) "owfile/owfile.cpp"

$(IntermediateDirectory)/owZip_owZip.cpp$(ObjectSuffix): owZip/owZip.cpp $(IntermediateDirectory)/owZip_owZip.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/ResourceManager/owZip/owZip.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/owZip_owZip.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/owZip_owZip.cpp$(DependSuffix): owZip/owZip.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/owZip_owZip.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/owZip_owZip.cpp$(DependSuffix) -MM "owZip/owZip.cpp"

$(IntermediateDirectory)/owZip_owZip.cpp$(PreprocessSuffix): owZip/owZip.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/owZip_owZip.cpp$(PreprocessSuffix) "owZip/owZip.cpp"

$(IntermediateDirectory)/algorithm_md5.cpp$(ObjectSuffix): algorithm/md5.cpp $(IntermediateDirectory)/algorithm_md5.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/ResourceManager/algorithm/md5.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/algorithm_md5.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/algorithm_md5.cpp$(DependSuffix): algorithm/md5.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/algorithm_md5.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/algorithm_md5.cpp$(DependSuffix) -MM "algorithm/md5.cpp"

$(IntermediateDirectory)/algorithm_md5.cpp$(PreprocessSuffix): algorithm/md5.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/algorithm_md5.cpp$(PreprocessSuffix) "algorithm/md5.cpp"

$(IntermediateDirectory)/package_owPackage.cpp$(ObjectSuffix): package/owPackage.cpp $(IntermediateDirectory)/package_owPackage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/ResourceManager/package/owPackage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/package_owPackage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/package_owPackage.cpp$(DependSuffix): package/owPackage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/package_owPackage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/package_owPackage.cpp$(DependSuffix) -MM "package/owPackage.cpp"

$(IntermediateDirectory)/package_owPackage.cpp$(PreprocessSuffix): package/owPackage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/package_owPackage.cpp$(PreprocessSuffix) "package/owPackage.cpp"

$(IntermediateDirectory)/package_package_common.cpp$(ObjectSuffix): package/package_common.cpp $(IntermediateDirectory)/package_package_common.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/ResourceManager/package/package_common.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/package_package_common.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/package_package_common.cpp$(DependSuffix): package/package_common.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/package_package_common.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/package_package_common.cpp$(DependSuffix) -MM "package/package_common.cpp"

$(IntermediateDirectory)/package_package_common.cpp$(PreprocessSuffix): package/package_common.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/package_package_common.cpp$(PreprocessSuffix) "package/package_common.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(BuildDir)/$(ProjectName)/Debug/


