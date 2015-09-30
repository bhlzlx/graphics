##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=audio
ConfigurationName      :=Debug
WorkspacePath          := "E:\projects\graphics"
ProjectPath            := "E:\projects\graphics\audio"
IntermediateDirectory  :=$(BuildDir)/$(ProjectName)/Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=phantom
Date                   :=01/10/2015
CodeLitePath           :="D:\app\CodeLite"
LinkerName             :=F:/tdmgcc/bin/g++.exe
SharedObjectLinkerName :=F:/tdmgcc/bin/g++.exe -shared -fPIC
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
ObjectsFileList        :="audio.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=F:/tdmgcc/bin/windres.exe
LinkOptions            :=  -lz -lopenal32 -logg -lvorbisfile -liconv
IncludePath            := $(IncludeSwitch)F:/tdmgcclib/include $(IncludeSwitch)F:/tdmgcclib/include/freetype $(IncludeSwitch)E:/projects/graphics/ow  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)../ow 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                :=$(LibraryPathSwitch)F:/tdmgcclib/lib  $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := F:/tdmgcc/bin/ar.exe rcu
CXX      := F:/tdmgcc/bin/g++.exe
CC       := F:/tdmgcc/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall -std=gnu++0x $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := F:/tdmgcc/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=D:\app\CodeLite
BuildDir:=E:/projects/builds
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/owcmn_EncodeCommon.cpp$(ObjectSuffix) $(IntermediateDirectory)/owcmn_owcmn.cpp$(ObjectSuffix) $(IntermediateDirectory)/owcmn_ResourcePool.cpp$(ObjectSuffix) $(IntermediateDirectory)/algorithm_md5.cpp$(ObjectSuffix) $(IntermediateDirectory)/audio_owAudio.cpp$(ObjectSuffix) $(IntermediateDirectory)/buffer_buffer.cpp$(ObjectSuffix) $(IntermediateDirectory)/memory_memory.cpp$(ObjectSuffix) $(IntermediateDirectory)/owfile_owfile.cpp$(ObjectSuffix) $(IntermediateDirectory)/owZip_owZip.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/package_owPackage.cpp$(ObjectSuffix) $(IntermediateDirectory)/package_package_common.cpp$(ObjectSuffix) $(IntermediateDirectory)/settings_settings.cpp$(ObjectSuffix) $(IntermediateDirectory)/log_logger.cpp$(ObjectSuffix) 



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
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/audio/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/owcmn_EncodeCommon.cpp$(ObjectSuffix): ../ow/owcmn/EncodeCommon.cpp $(IntermediateDirectory)/owcmn_EncodeCommon.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/ow/owcmn/EncodeCommon.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/owcmn_EncodeCommon.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/owcmn_EncodeCommon.cpp$(DependSuffix): ../ow/owcmn/EncodeCommon.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/owcmn_EncodeCommon.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/owcmn_EncodeCommon.cpp$(DependSuffix) -MM "../ow/owcmn/EncodeCommon.cpp"

$(IntermediateDirectory)/owcmn_EncodeCommon.cpp$(PreprocessSuffix): ../ow/owcmn/EncodeCommon.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/owcmn_EncodeCommon.cpp$(PreprocessSuffix) "../ow/owcmn/EncodeCommon.cpp"

$(IntermediateDirectory)/owcmn_owcmn.cpp$(ObjectSuffix): ../ow/owcmn/owcmn.cpp $(IntermediateDirectory)/owcmn_owcmn.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/ow/owcmn/owcmn.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/owcmn_owcmn.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/owcmn_owcmn.cpp$(DependSuffix): ../ow/owcmn/owcmn.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/owcmn_owcmn.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/owcmn_owcmn.cpp$(DependSuffix) -MM "../ow/owcmn/owcmn.cpp"

$(IntermediateDirectory)/owcmn_owcmn.cpp$(PreprocessSuffix): ../ow/owcmn/owcmn.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/owcmn_owcmn.cpp$(PreprocessSuffix) "../ow/owcmn/owcmn.cpp"

$(IntermediateDirectory)/owcmn_ResourcePool.cpp$(ObjectSuffix): ../ow/owcmn/ResourcePool.cpp $(IntermediateDirectory)/owcmn_ResourcePool.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/ow/owcmn/ResourcePool.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/owcmn_ResourcePool.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/owcmn_ResourcePool.cpp$(DependSuffix): ../ow/owcmn/ResourcePool.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/owcmn_ResourcePool.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/owcmn_ResourcePool.cpp$(DependSuffix) -MM "../ow/owcmn/ResourcePool.cpp"

$(IntermediateDirectory)/owcmn_ResourcePool.cpp$(PreprocessSuffix): ../ow/owcmn/ResourcePool.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/owcmn_ResourcePool.cpp$(PreprocessSuffix) "../ow/owcmn/ResourcePool.cpp"

$(IntermediateDirectory)/algorithm_md5.cpp$(ObjectSuffix): ../ow/algorithm/md5.cpp $(IntermediateDirectory)/algorithm_md5.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/ow/algorithm/md5.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/algorithm_md5.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/algorithm_md5.cpp$(DependSuffix): ../ow/algorithm/md5.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/algorithm_md5.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/algorithm_md5.cpp$(DependSuffix) -MM "../ow/algorithm/md5.cpp"

$(IntermediateDirectory)/algorithm_md5.cpp$(PreprocessSuffix): ../ow/algorithm/md5.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/algorithm_md5.cpp$(PreprocessSuffix) "../ow/algorithm/md5.cpp"

$(IntermediateDirectory)/audio_owAudio.cpp$(ObjectSuffix): ../ow/audio/owAudio.cpp $(IntermediateDirectory)/audio_owAudio.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/ow/audio/owAudio.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/audio_owAudio.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/audio_owAudio.cpp$(DependSuffix): ../ow/audio/owAudio.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/audio_owAudio.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/audio_owAudio.cpp$(DependSuffix) -MM "../ow/audio/owAudio.cpp"

$(IntermediateDirectory)/audio_owAudio.cpp$(PreprocessSuffix): ../ow/audio/owAudio.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/audio_owAudio.cpp$(PreprocessSuffix) "../ow/audio/owAudio.cpp"

$(IntermediateDirectory)/buffer_buffer.cpp$(ObjectSuffix): ../ow/buffer/buffer.cpp $(IntermediateDirectory)/buffer_buffer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/ow/buffer/buffer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/buffer_buffer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/buffer_buffer.cpp$(DependSuffix): ../ow/buffer/buffer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/buffer_buffer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/buffer_buffer.cpp$(DependSuffix) -MM "../ow/buffer/buffer.cpp"

$(IntermediateDirectory)/buffer_buffer.cpp$(PreprocessSuffix): ../ow/buffer/buffer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/buffer_buffer.cpp$(PreprocessSuffix) "../ow/buffer/buffer.cpp"

$(IntermediateDirectory)/memory_memory.cpp$(ObjectSuffix): ../ow/memory/memory.cpp $(IntermediateDirectory)/memory_memory.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/ow/memory/memory.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/memory_memory.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/memory_memory.cpp$(DependSuffix): ../ow/memory/memory.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/memory_memory.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/memory_memory.cpp$(DependSuffix) -MM "../ow/memory/memory.cpp"

$(IntermediateDirectory)/memory_memory.cpp$(PreprocessSuffix): ../ow/memory/memory.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/memory_memory.cpp$(PreprocessSuffix) "../ow/memory/memory.cpp"

$(IntermediateDirectory)/owfile_owfile.cpp$(ObjectSuffix): ../ow/owfile/owfile.cpp $(IntermediateDirectory)/owfile_owfile.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/ow/owfile/owfile.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/owfile_owfile.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/owfile_owfile.cpp$(DependSuffix): ../ow/owfile/owfile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/owfile_owfile.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/owfile_owfile.cpp$(DependSuffix) -MM "../ow/owfile/owfile.cpp"

$(IntermediateDirectory)/owfile_owfile.cpp$(PreprocessSuffix): ../ow/owfile/owfile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/owfile_owfile.cpp$(PreprocessSuffix) "../ow/owfile/owfile.cpp"

$(IntermediateDirectory)/owZip_owZip.cpp$(ObjectSuffix): ../ow/owZip/owZip.cpp $(IntermediateDirectory)/owZip_owZip.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/ow/owZip/owZip.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/owZip_owZip.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/owZip_owZip.cpp$(DependSuffix): ../ow/owZip/owZip.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/owZip_owZip.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/owZip_owZip.cpp$(DependSuffix) -MM "../ow/owZip/owZip.cpp"

$(IntermediateDirectory)/owZip_owZip.cpp$(PreprocessSuffix): ../ow/owZip/owZip.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/owZip_owZip.cpp$(PreprocessSuffix) "../ow/owZip/owZip.cpp"

$(IntermediateDirectory)/package_owPackage.cpp$(ObjectSuffix): ../ow/package/owPackage.cpp $(IntermediateDirectory)/package_owPackage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/ow/package/owPackage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/package_owPackage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/package_owPackage.cpp$(DependSuffix): ../ow/package/owPackage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/package_owPackage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/package_owPackage.cpp$(DependSuffix) -MM "../ow/package/owPackage.cpp"

$(IntermediateDirectory)/package_owPackage.cpp$(PreprocessSuffix): ../ow/package/owPackage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/package_owPackage.cpp$(PreprocessSuffix) "../ow/package/owPackage.cpp"

$(IntermediateDirectory)/package_package_common.cpp$(ObjectSuffix): ../ow/package/package_common.cpp $(IntermediateDirectory)/package_package_common.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/ow/package/package_common.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/package_package_common.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/package_package_common.cpp$(DependSuffix): ../ow/package/package_common.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/package_package_common.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/package_package_common.cpp$(DependSuffix) -MM "../ow/package/package_common.cpp"

$(IntermediateDirectory)/package_package_common.cpp$(PreprocessSuffix): ../ow/package/package_common.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/package_package_common.cpp$(PreprocessSuffix) "../ow/package/package_common.cpp"

$(IntermediateDirectory)/settings_settings.cpp$(ObjectSuffix): ../ow/settings/settings.cpp $(IntermediateDirectory)/settings_settings.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/ow/settings/settings.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/settings_settings.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/settings_settings.cpp$(DependSuffix): ../ow/settings/settings.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/settings_settings.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/settings_settings.cpp$(DependSuffix) -MM "../ow/settings/settings.cpp"

$(IntermediateDirectory)/settings_settings.cpp$(PreprocessSuffix): ../ow/settings/settings.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/settings_settings.cpp$(PreprocessSuffix) "../ow/settings/settings.cpp"

$(IntermediateDirectory)/log_logger.cpp$(ObjectSuffix): ../ow/owcmn/log/logger.cpp $(IntermediateDirectory)/log_logger.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/ow/owcmn/log/logger.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/log_logger.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/log_logger.cpp$(DependSuffix): ../ow/owcmn/log/logger.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/log_logger.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/log_logger.cpp$(DependSuffix) -MM "../ow/owcmn/log/logger.cpp"

$(IntermediateDirectory)/log_logger.cpp$(PreprocessSuffix): ../ow/owcmn/log/logger.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/log_logger.cpp$(PreprocessSuffix) "../ow/owcmn/log/logger.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(BuildDir)/$(ProjectName)/Debug/


