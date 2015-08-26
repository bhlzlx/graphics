##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=core
ConfigurationName      :=Debug
WorkspacePath          := "E:\projects\graphics"
ProjectPath            := "E:\projects\graphics\core"
IntermediateDirectory  :=E:/projects/builds/$(ProjectName)/Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Administrator
Date                   :=26/08/2015
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
ObjectsFileList        :="core.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=E:/tdmgcc32/bin/windres.exe
LinkOptions            :=  -lglew32 -lglfw3 -lpng -lz -lgdi32 -lopengl32
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
CXXFLAGS :=  -g -O0 -Wall -std=c++11 -I./core $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := E:/tdmgcc32/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=E:\application\CodeLite
Objects0=$(IntermediateDirectory)/model_MD5Model.cpp$(ObjectSuffix) $(IntermediateDirectory)/model_models.cpp$(ObjectSuffix) $(IntermediateDirectory)/math_Camera.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/app_AppDelegate.cpp$(ObjectSuffix) $(IntermediateDirectory)/app_OpenGLViewController.cpp$(ObjectSuffix) $(IntermediateDirectory)/buffer_buffer.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_BufferOGL.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_DepthStencilOGL.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_EffectOGL.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/core_Image.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_RenderPipelineOGL.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_RenderTargetOGL.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_ShaderOGL.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_TexOGL.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_UICommon.cpp$(ObjectSuffix) $(IntermediateDirectory)/event_MouseEvent.cpp$(ObjectSuffix) $(IntermediateDirectory)/md5_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/md5_md5.cpp$(ObjectSuffix) $(IntermediateDirectory)/md5_md5Frame.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/log_logger.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/model_MD5Model.cpp$(ObjectSuffix): model/MD5Model.cpp $(IntermediateDirectory)/model_MD5Model.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/model/MD5Model.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/model_MD5Model.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/model_MD5Model.cpp$(DependSuffix): model/MD5Model.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/model_MD5Model.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/model_MD5Model.cpp$(DependSuffix) -MM "model/MD5Model.cpp"

$(IntermediateDirectory)/model_MD5Model.cpp$(PreprocessSuffix): model/MD5Model.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/model_MD5Model.cpp$(PreprocessSuffix) "model/MD5Model.cpp"

$(IntermediateDirectory)/model_models.cpp$(ObjectSuffix): model/models.cpp $(IntermediateDirectory)/model_models.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/model/models.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/model_models.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/model_models.cpp$(DependSuffix): model/models.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/model_models.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/model_models.cpp$(DependSuffix) -MM "model/models.cpp"

$(IntermediateDirectory)/model_models.cpp$(PreprocessSuffix): model/models.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/model_models.cpp$(PreprocessSuffix) "model/models.cpp"

$(IntermediateDirectory)/math_Camera.cpp$(ObjectSuffix): math/Camera.cpp $(IntermediateDirectory)/math_Camera.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/math/Camera.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/math_Camera.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/math_Camera.cpp$(DependSuffix): math/Camera.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/math_Camera.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/math_Camera.cpp$(DependSuffix) -MM "math/Camera.cpp"

$(IntermediateDirectory)/math_Camera.cpp$(PreprocessSuffix): math/Camera.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/math_Camera.cpp$(PreprocessSuffix) "math/Camera.cpp"

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/app_AppDelegate.cpp$(ObjectSuffix): app/AppDelegate.cpp $(IntermediateDirectory)/app_AppDelegate.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/app/AppDelegate.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/app_AppDelegate.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/app_AppDelegate.cpp$(DependSuffix): app/AppDelegate.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/app_AppDelegate.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/app_AppDelegate.cpp$(DependSuffix) -MM "app/AppDelegate.cpp"

$(IntermediateDirectory)/app_AppDelegate.cpp$(PreprocessSuffix): app/AppDelegate.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/app_AppDelegate.cpp$(PreprocessSuffix) "app/AppDelegate.cpp"

$(IntermediateDirectory)/app_OpenGLViewController.cpp$(ObjectSuffix): app/OpenGLViewController.cpp $(IntermediateDirectory)/app_OpenGLViewController.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/app/OpenGLViewController.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/app_OpenGLViewController.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/app_OpenGLViewController.cpp$(DependSuffix): app/OpenGLViewController.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/app_OpenGLViewController.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/app_OpenGLViewController.cpp$(DependSuffix) -MM "app/OpenGLViewController.cpp"

$(IntermediateDirectory)/app_OpenGLViewController.cpp$(PreprocessSuffix): app/OpenGLViewController.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/app_OpenGLViewController.cpp$(PreprocessSuffix) "app/OpenGLViewController.cpp"

$(IntermediateDirectory)/buffer_buffer.cpp$(ObjectSuffix): buffer/buffer.cpp $(IntermediateDirectory)/buffer_buffer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/buffer/buffer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/buffer_buffer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/buffer_buffer.cpp$(DependSuffix): buffer/buffer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/buffer_buffer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/buffer_buffer.cpp$(DependSuffix) -MM "buffer/buffer.cpp"

$(IntermediateDirectory)/buffer_buffer.cpp$(PreprocessSuffix): buffer/buffer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/buffer_buffer.cpp$(PreprocessSuffix) "buffer/buffer.cpp"

$(IntermediateDirectory)/core_BufferOGL.cpp$(ObjectSuffix): core/BufferOGL.cpp $(IntermediateDirectory)/core_BufferOGL.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/core/BufferOGL.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_BufferOGL.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_BufferOGL.cpp$(DependSuffix): core/BufferOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_BufferOGL.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/core_BufferOGL.cpp$(DependSuffix) -MM "core/BufferOGL.cpp"

$(IntermediateDirectory)/core_BufferOGL.cpp$(PreprocessSuffix): core/BufferOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_BufferOGL.cpp$(PreprocessSuffix) "core/BufferOGL.cpp"

$(IntermediateDirectory)/core_DepthStencilOGL.cpp$(ObjectSuffix): core/DepthStencilOGL.cpp $(IntermediateDirectory)/core_DepthStencilOGL.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/core/DepthStencilOGL.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_DepthStencilOGL.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_DepthStencilOGL.cpp$(DependSuffix): core/DepthStencilOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_DepthStencilOGL.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/core_DepthStencilOGL.cpp$(DependSuffix) -MM "core/DepthStencilOGL.cpp"

$(IntermediateDirectory)/core_DepthStencilOGL.cpp$(PreprocessSuffix): core/DepthStencilOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_DepthStencilOGL.cpp$(PreprocessSuffix) "core/DepthStencilOGL.cpp"

$(IntermediateDirectory)/core_EffectOGL.cpp$(ObjectSuffix): core/EffectOGL.cpp $(IntermediateDirectory)/core_EffectOGL.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/core/EffectOGL.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_EffectOGL.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_EffectOGL.cpp$(DependSuffix): core/EffectOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_EffectOGL.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/core_EffectOGL.cpp$(DependSuffix) -MM "core/EffectOGL.cpp"

$(IntermediateDirectory)/core_EffectOGL.cpp$(PreprocessSuffix): core/EffectOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_EffectOGL.cpp$(PreprocessSuffix) "core/EffectOGL.cpp"

$(IntermediateDirectory)/core_Image.cpp$(ObjectSuffix): core/Image.cpp $(IntermediateDirectory)/core_Image.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/core/Image.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_Image.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_Image.cpp$(DependSuffix): core/Image.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_Image.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/core_Image.cpp$(DependSuffix) -MM "core/Image.cpp"

$(IntermediateDirectory)/core_Image.cpp$(PreprocessSuffix): core/Image.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_Image.cpp$(PreprocessSuffix) "core/Image.cpp"

$(IntermediateDirectory)/core_RenderPipelineOGL.cpp$(ObjectSuffix): core/RenderPipelineOGL.cpp $(IntermediateDirectory)/core_RenderPipelineOGL.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/core/RenderPipelineOGL.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_RenderPipelineOGL.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_RenderPipelineOGL.cpp$(DependSuffix): core/RenderPipelineOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_RenderPipelineOGL.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/core_RenderPipelineOGL.cpp$(DependSuffix) -MM "core/RenderPipelineOGL.cpp"

$(IntermediateDirectory)/core_RenderPipelineOGL.cpp$(PreprocessSuffix): core/RenderPipelineOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_RenderPipelineOGL.cpp$(PreprocessSuffix) "core/RenderPipelineOGL.cpp"

$(IntermediateDirectory)/core_RenderTargetOGL.cpp$(ObjectSuffix): core/RenderTargetOGL.cpp $(IntermediateDirectory)/core_RenderTargetOGL.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/core/RenderTargetOGL.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_RenderTargetOGL.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_RenderTargetOGL.cpp$(DependSuffix): core/RenderTargetOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_RenderTargetOGL.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/core_RenderTargetOGL.cpp$(DependSuffix) -MM "core/RenderTargetOGL.cpp"

$(IntermediateDirectory)/core_RenderTargetOGL.cpp$(PreprocessSuffix): core/RenderTargetOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_RenderTargetOGL.cpp$(PreprocessSuffix) "core/RenderTargetOGL.cpp"

$(IntermediateDirectory)/core_ShaderOGL.cpp$(ObjectSuffix): core/ShaderOGL.cpp $(IntermediateDirectory)/core_ShaderOGL.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/core/ShaderOGL.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_ShaderOGL.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_ShaderOGL.cpp$(DependSuffix): core/ShaderOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_ShaderOGL.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/core_ShaderOGL.cpp$(DependSuffix) -MM "core/ShaderOGL.cpp"

$(IntermediateDirectory)/core_ShaderOGL.cpp$(PreprocessSuffix): core/ShaderOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_ShaderOGL.cpp$(PreprocessSuffix) "core/ShaderOGL.cpp"

$(IntermediateDirectory)/core_TexOGL.cpp$(ObjectSuffix): core/TexOGL.cpp $(IntermediateDirectory)/core_TexOGL.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/core/TexOGL.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_TexOGL.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_TexOGL.cpp$(DependSuffix): core/TexOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_TexOGL.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/core_TexOGL.cpp$(DependSuffix) -MM "core/TexOGL.cpp"

$(IntermediateDirectory)/core_TexOGL.cpp$(PreprocessSuffix): core/TexOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_TexOGL.cpp$(PreprocessSuffix) "core/TexOGL.cpp"

$(IntermediateDirectory)/core_UICommon.cpp$(ObjectSuffix): core/UICommon.cpp $(IntermediateDirectory)/core_UICommon.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/core/UICommon.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_UICommon.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_UICommon.cpp$(DependSuffix): core/UICommon.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_UICommon.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/core_UICommon.cpp$(DependSuffix) -MM "core/UICommon.cpp"

$(IntermediateDirectory)/core_UICommon.cpp$(PreprocessSuffix): core/UICommon.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_UICommon.cpp$(PreprocessSuffix) "core/UICommon.cpp"

$(IntermediateDirectory)/event_MouseEvent.cpp$(ObjectSuffix): event/MouseEvent.cpp $(IntermediateDirectory)/event_MouseEvent.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/event/MouseEvent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/event_MouseEvent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/event_MouseEvent.cpp$(DependSuffix): event/MouseEvent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/event_MouseEvent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/event_MouseEvent.cpp$(DependSuffix) -MM "event/MouseEvent.cpp"

$(IntermediateDirectory)/event_MouseEvent.cpp$(PreprocessSuffix): event/MouseEvent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/event_MouseEvent.cpp$(PreprocessSuffix) "event/MouseEvent.cpp"

$(IntermediateDirectory)/md5_main.cpp$(ObjectSuffix): model/md5/main.cpp $(IntermediateDirectory)/md5_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/model/md5/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/md5_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/md5_main.cpp$(DependSuffix): model/md5/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/md5_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/md5_main.cpp$(DependSuffix) -MM "model/md5/main.cpp"

$(IntermediateDirectory)/md5_main.cpp$(PreprocessSuffix): model/md5/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/md5_main.cpp$(PreprocessSuffix) "model/md5/main.cpp"

$(IntermediateDirectory)/md5_md5.cpp$(ObjectSuffix): model/md5/md5.cpp $(IntermediateDirectory)/md5_md5.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/model/md5/md5.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/md5_md5.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/md5_md5.cpp$(DependSuffix): model/md5/md5.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/md5_md5.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/md5_md5.cpp$(DependSuffix) -MM "model/md5/md5.cpp"

$(IntermediateDirectory)/md5_md5.cpp$(PreprocessSuffix): model/md5/md5.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/md5_md5.cpp$(PreprocessSuffix) "model/md5/md5.cpp"

$(IntermediateDirectory)/md5_md5Frame.cpp$(ObjectSuffix): model/md5/md5Frame.cpp $(IntermediateDirectory)/md5_md5Frame.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/model/md5/md5Frame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/md5_md5Frame.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/md5_md5Frame.cpp$(DependSuffix): model/md5/md5Frame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/md5_md5Frame.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/md5_md5Frame.cpp$(DependSuffix) -MM "model/md5/md5Frame.cpp"

$(IntermediateDirectory)/md5_md5Frame.cpp$(PreprocessSuffix): model/md5/md5Frame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/md5_md5Frame.cpp$(PreprocessSuffix) "model/md5/md5Frame.cpp"

$(IntermediateDirectory)/log_logger.cpp$(ObjectSuffix): common/log/logger.cpp $(IntermediateDirectory)/log_logger.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/common/log/logger.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/log_logger.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/log_logger.cpp$(DependSuffix): common/log/logger.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/log_logger.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/log_logger.cpp$(DependSuffix) -MM "common/log/logger.cpp"

$(IntermediateDirectory)/log_logger.cpp$(PreprocessSuffix): common/log/logger.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/log_logger.cpp$(PreprocessSuffix) "common/log/logger.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r E:/projects/builds/$(ProjectName)/Debug/


