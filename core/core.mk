##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=core
ConfigurationName      :=Debug
WorkspacePath          := "E:\projects\graphics"
ProjectPath            := "E:\projects\graphics\core"
IntermediateDirectory  :=$(BuildDir)/$(ProjectName)/Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=phantom
Date                   :=15/09/2015
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
ObjectsFileList        :="core.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=F:/tdmgcc/bin/windres.exe
LinkOptions            :=  -lglew32 -lglfw3 -lpng -lz -lgdi32 -lopengl32 -lfreetype -liconv
IncludePath            := $(IncludeSwitch)F:/tdmgcclib/include $(IncludeSwitch)F:/tdmgcclib/include/freetype  $(IncludeSwitch). $(IncludeSwitch). 
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
CXXFLAGS :=  -g -O0 -Wall -std=c++11  $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := F:/tdmgcc/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=D:\app\CodeLite
BuildDir:=E:/projects/builds
Objects0=$(IntermediateDirectory)/model_BasicModel.cpp$(ObjectSuffix) $(IntermediateDirectory)/math_Camera.cpp$(ObjectSuffix) $(IntermediateDirectory)/math_Variance.cpp$(ObjectSuffix) $(IntermediateDirectory)/common_EncodeCommon.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/app_AppDelegate.cpp$(ObjectSuffix) $(IntermediateDirectory)/app_OpenGLViewController.cpp$(ObjectSuffix) $(IntermediateDirectory)/buffer_buffer.cpp$(ObjectSuffix) $(IntermediateDirectory)/event_MouseEvent.cpp$(ObjectSuffix) $(IntermediateDirectory)/scene_GameScene.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/scene_SceneObject.cpp$(ObjectSuffix) $(IntermediateDirectory)/algorithm_md5.cpp$(ObjectSuffix) $(IntermediateDirectory)/gui_Label.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_BufferOGL.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_DepthStencilOGL.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_EffectOGL.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_Image.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_RenderPipelineOGL.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_RenderTargetOGL.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_ShaderOGL.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/core_TexOGL.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_UICommon.cpp$(ObjectSuffix) $(IntermediateDirectory)/memory_memory.cpp$(ObjectSuffix) $(IntermediateDirectory)/settings_settings.cpp$(ObjectSuffix) $(IntermediateDirectory)/md5parser_md5.cpp$(ObjectSuffix) $(IntermediateDirectory)/md5parser_md5Model.cpp$(ObjectSuffix) $(IntermediateDirectory)/log_logger.cpp$(ObjectSuffix) $(IntermediateDirectory)/aabb_aabb.cpp$(ObjectSuffix) $(IntermediateDirectory)/octree_Octree.cpp$(ObjectSuffix) $(IntermediateDirectory)/octree_OctreeRenderNode.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/renderer_TextRenderer.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/model_BasicModel.cpp$(ObjectSuffix): model/BasicModel.cpp $(IntermediateDirectory)/model_BasicModel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/model/BasicModel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/model_BasicModel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/model_BasicModel.cpp$(DependSuffix): model/BasicModel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/model_BasicModel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/model_BasicModel.cpp$(DependSuffix) -MM "model/BasicModel.cpp"

$(IntermediateDirectory)/model_BasicModel.cpp$(PreprocessSuffix): model/BasicModel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/model_BasicModel.cpp$(PreprocessSuffix) "model/BasicModel.cpp"

$(IntermediateDirectory)/math_Camera.cpp$(ObjectSuffix): math/Camera.cpp $(IntermediateDirectory)/math_Camera.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/math/Camera.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/math_Camera.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/math_Camera.cpp$(DependSuffix): math/Camera.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/math_Camera.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/math_Camera.cpp$(DependSuffix) -MM "math/Camera.cpp"

$(IntermediateDirectory)/math_Camera.cpp$(PreprocessSuffix): math/Camera.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/math_Camera.cpp$(PreprocessSuffix) "math/Camera.cpp"

$(IntermediateDirectory)/math_Variance.cpp$(ObjectSuffix): math/Variance.cpp $(IntermediateDirectory)/math_Variance.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/math/Variance.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/math_Variance.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/math_Variance.cpp$(DependSuffix): math/Variance.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/math_Variance.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/math_Variance.cpp$(DependSuffix) -MM "math/Variance.cpp"

$(IntermediateDirectory)/math_Variance.cpp$(PreprocessSuffix): math/Variance.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/math_Variance.cpp$(PreprocessSuffix) "math/Variance.cpp"

$(IntermediateDirectory)/common_EncodeCommon.cpp$(ObjectSuffix): common/EncodeCommon.cpp $(IntermediateDirectory)/common_EncodeCommon.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/common/EncodeCommon.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/common_EncodeCommon.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/common_EncodeCommon.cpp$(DependSuffix): common/EncodeCommon.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/common_EncodeCommon.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/common_EncodeCommon.cpp$(DependSuffix) -MM "common/EncodeCommon.cpp"

$(IntermediateDirectory)/common_EncodeCommon.cpp$(PreprocessSuffix): common/EncodeCommon.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/common_EncodeCommon.cpp$(PreprocessSuffix) "common/EncodeCommon.cpp"

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

$(IntermediateDirectory)/event_MouseEvent.cpp$(ObjectSuffix): event/MouseEvent.cpp $(IntermediateDirectory)/event_MouseEvent.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/event/MouseEvent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/event_MouseEvent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/event_MouseEvent.cpp$(DependSuffix): event/MouseEvent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/event_MouseEvent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/event_MouseEvent.cpp$(DependSuffix) -MM "event/MouseEvent.cpp"

$(IntermediateDirectory)/event_MouseEvent.cpp$(PreprocessSuffix): event/MouseEvent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/event_MouseEvent.cpp$(PreprocessSuffix) "event/MouseEvent.cpp"

$(IntermediateDirectory)/scene_GameScene.cpp$(ObjectSuffix): scene/GameScene.cpp $(IntermediateDirectory)/scene_GameScene.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/scene/GameScene.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/scene_GameScene.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/scene_GameScene.cpp$(DependSuffix): scene/GameScene.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/scene_GameScene.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/scene_GameScene.cpp$(DependSuffix) -MM "scene/GameScene.cpp"

$(IntermediateDirectory)/scene_GameScene.cpp$(PreprocessSuffix): scene/GameScene.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/scene_GameScene.cpp$(PreprocessSuffix) "scene/GameScene.cpp"

$(IntermediateDirectory)/scene_SceneObject.cpp$(ObjectSuffix): scene/SceneObject.cpp $(IntermediateDirectory)/scene_SceneObject.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/scene/SceneObject.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/scene_SceneObject.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/scene_SceneObject.cpp$(DependSuffix): scene/SceneObject.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/scene_SceneObject.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/scene_SceneObject.cpp$(DependSuffix) -MM "scene/SceneObject.cpp"

$(IntermediateDirectory)/scene_SceneObject.cpp$(PreprocessSuffix): scene/SceneObject.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/scene_SceneObject.cpp$(PreprocessSuffix) "scene/SceneObject.cpp"

$(IntermediateDirectory)/algorithm_md5.cpp$(ObjectSuffix): algorithm/md5.cpp $(IntermediateDirectory)/algorithm_md5.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/algorithm/md5.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/algorithm_md5.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/algorithm_md5.cpp$(DependSuffix): algorithm/md5.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/algorithm_md5.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/algorithm_md5.cpp$(DependSuffix) -MM "algorithm/md5.cpp"

$(IntermediateDirectory)/algorithm_md5.cpp$(PreprocessSuffix): algorithm/md5.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/algorithm_md5.cpp$(PreprocessSuffix) "algorithm/md5.cpp"

$(IntermediateDirectory)/gui_Label.cpp$(ObjectSuffix): gui/Label.cpp $(IntermediateDirectory)/gui_Label.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/gui/Label.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gui_Label.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_Label.cpp$(DependSuffix): gui/Label.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_Label.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_Label.cpp$(DependSuffix) -MM "gui/Label.cpp"

$(IntermediateDirectory)/gui_Label.cpp$(PreprocessSuffix): gui/Label.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_Label.cpp$(PreprocessSuffix) "gui/Label.cpp"

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

$(IntermediateDirectory)/memory_memory.cpp$(ObjectSuffix): memory/memory.cpp $(IntermediateDirectory)/memory_memory.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/memory/memory.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/memory_memory.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/memory_memory.cpp$(DependSuffix): memory/memory.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/memory_memory.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/memory_memory.cpp$(DependSuffix) -MM "memory/memory.cpp"

$(IntermediateDirectory)/memory_memory.cpp$(PreprocessSuffix): memory/memory.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/memory_memory.cpp$(PreprocessSuffix) "memory/memory.cpp"

$(IntermediateDirectory)/settings_settings.cpp$(ObjectSuffix): settings/settings.cpp $(IntermediateDirectory)/settings_settings.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/settings/settings.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/settings_settings.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/settings_settings.cpp$(DependSuffix): settings/settings.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/settings_settings.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/settings_settings.cpp$(DependSuffix) -MM "settings/settings.cpp"

$(IntermediateDirectory)/settings_settings.cpp$(PreprocessSuffix): settings/settings.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/settings_settings.cpp$(PreprocessSuffix) "settings/settings.cpp"

$(IntermediateDirectory)/md5parser_md5.cpp$(ObjectSuffix): model/md5parser/md5.cpp $(IntermediateDirectory)/md5parser_md5.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/model/md5parser/md5.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/md5parser_md5.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/md5parser_md5.cpp$(DependSuffix): model/md5parser/md5.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/md5parser_md5.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/md5parser_md5.cpp$(DependSuffix) -MM "model/md5parser/md5.cpp"

$(IntermediateDirectory)/md5parser_md5.cpp$(PreprocessSuffix): model/md5parser/md5.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/md5parser_md5.cpp$(PreprocessSuffix) "model/md5parser/md5.cpp"

$(IntermediateDirectory)/md5parser_md5Model.cpp$(ObjectSuffix): model/md5parser/md5Model.cpp $(IntermediateDirectory)/md5parser_md5Model.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/model/md5parser/md5Model.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/md5parser_md5Model.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/md5parser_md5Model.cpp$(DependSuffix): model/md5parser/md5Model.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/md5parser_md5Model.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/md5parser_md5Model.cpp$(DependSuffix) -MM "model/md5parser/md5Model.cpp"

$(IntermediateDirectory)/md5parser_md5Model.cpp$(PreprocessSuffix): model/md5parser/md5Model.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/md5parser_md5Model.cpp$(PreprocessSuffix) "model/md5parser/md5Model.cpp"

$(IntermediateDirectory)/log_logger.cpp$(ObjectSuffix): common/log/logger.cpp $(IntermediateDirectory)/log_logger.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/common/log/logger.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/log_logger.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/log_logger.cpp$(DependSuffix): common/log/logger.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/log_logger.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/log_logger.cpp$(DependSuffix) -MM "common/log/logger.cpp"

$(IntermediateDirectory)/log_logger.cpp$(PreprocessSuffix): common/log/logger.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/log_logger.cpp$(PreprocessSuffix) "common/log/logger.cpp"

$(IntermediateDirectory)/aabb_aabb.cpp$(ObjectSuffix): scene/aabb/aabb.cpp $(IntermediateDirectory)/aabb_aabb.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/scene/aabb/aabb.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/aabb_aabb.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/aabb_aabb.cpp$(DependSuffix): scene/aabb/aabb.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/aabb_aabb.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/aabb_aabb.cpp$(DependSuffix) -MM "scene/aabb/aabb.cpp"

$(IntermediateDirectory)/aabb_aabb.cpp$(PreprocessSuffix): scene/aabb/aabb.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/aabb_aabb.cpp$(PreprocessSuffix) "scene/aabb/aabb.cpp"

$(IntermediateDirectory)/octree_Octree.cpp$(ObjectSuffix): scene/octree/Octree.cpp $(IntermediateDirectory)/octree_Octree.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/scene/octree/Octree.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/octree_Octree.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/octree_Octree.cpp$(DependSuffix): scene/octree/Octree.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/octree_Octree.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/octree_Octree.cpp$(DependSuffix) -MM "scene/octree/Octree.cpp"

$(IntermediateDirectory)/octree_Octree.cpp$(PreprocessSuffix): scene/octree/Octree.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/octree_Octree.cpp$(PreprocessSuffix) "scene/octree/Octree.cpp"

$(IntermediateDirectory)/octree_OctreeRenderNode.cpp$(ObjectSuffix): scene/octree/OctreeRenderNode.cpp $(IntermediateDirectory)/octree_OctreeRenderNode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/scene/octree/OctreeRenderNode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/octree_OctreeRenderNode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/octree_OctreeRenderNode.cpp$(DependSuffix): scene/octree/OctreeRenderNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/octree_OctreeRenderNode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/octree_OctreeRenderNode.cpp$(DependSuffix) -MM "scene/octree/OctreeRenderNode.cpp"

$(IntermediateDirectory)/octree_OctreeRenderNode.cpp$(PreprocessSuffix): scene/octree/OctreeRenderNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/octree_OctreeRenderNode.cpp$(PreprocessSuffix) "scene/octree/OctreeRenderNode.cpp"

$(IntermediateDirectory)/renderer_TextRenderer.cpp$(ObjectSuffix): core/renderer/TextRenderer.cpp $(IntermediateDirectory)/renderer_TextRenderer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/core/renderer/TextRenderer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/renderer_TextRenderer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/renderer_TextRenderer.cpp$(DependSuffix): core/renderer/TextRenderer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/renderer_TextRenderer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/renderer_TextRenderer.cpp$(DependSuffix) -MM "core/renderer/TextRenderer.cpp"

$(IntermediateDirectory)/renderer_TextRenderer.cpp$(PreprocessSuffix): core/renderer/TextRenderer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/renderer_TextRenderer.cpp$(PreprocessSuffix) "core/renderer/TextRenderer.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(BuildDir)/$(ProjectName)/Debug/


