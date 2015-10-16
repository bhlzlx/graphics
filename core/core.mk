##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=core
ConfigurationName      :=Release
WorkspacePath          := "F:\gits\graphics"
ProjectPath            := "F:\gits\graphics\core"
IntermediateDirectory  :=$(BuildDir)/$(ProjectName)/Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Administrator
Date                   :=16/10/2015
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
OutputFile             :=$(BuildDir)/$(ProjectName)/$(ProjectName)_release
Preprocessors          :=$(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="core.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=E:/tdmgcc32/bin/windres.exe
LinkOptions            :=  -lglew32 -lglfw3 -lpng -lz -lgdi32 -lopengl32 -lfreetype -liconv -lopenal32 -logg.dll -lvorbisfile.dll
IncludePath            := $(IncludeSwitch)E:/tdmgcclib/include $(IncludeSwitch)E:/tdmgcclib/include/freetype $(IncludeSwitch)F:/opengl/wxWidgets-3.0.2/include $(IncludeSwitch)F:/opengl/wxWidgets-3.0.2  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)../ow 
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
CXXFLAGS :=  -O2 -Wall -std=gnu++0x  $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := E:/tdmgcc32/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=E:\application\CodeLite
BuildDir:=E:/projects/builds
WXWIN:=G:/wxwidgets
WXCFG:=gcc_lib/mswud
Objects0=$(IntermediateDirectory)/scene_GameScene.cpp$(ObjectSuffix) $(IntermediateDirectory)/scene_SceneObject.cpp$(ObjectSuffix) $(IntermediateDirectory)/model_BasicModel.cpp$(ObjectSuffix) $(IntermediateDirectory)/model_MD5Model.cpp$(ObjectSuffix) $(IntermediateDirectory)/model_models.cpp$(ObjectSuffix) $(IntermediateDirectory)/math_Camera.cpp$(ObjectSuffix) $(IntermediateDirectory)/math_Variance.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_BufferOGL.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_DepthStencilOGL.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_EffectOGL.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/core_Image.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_RenderPipelineOGL.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_RenderTargetOGL.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_ShaderOGL.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_TexOGL.cpp$(ObjectSuffix) $(IntermediateDirectory)/app_AppDelegate.cpp$(ObjectSuffix) $(IntermediateDirectory)/app_OpenGLViewController.cpp$(ObjectSuffix) $(IntermediateDirectory)/event_MouseEvent.cpp$(ObjectSuffix) $(IntermediateDirectory)/gui_Label.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/audioManager_AudioManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/aabb_aabb.cpp$(ObjectSuffix) $(IntermediateDirectory)/octree_Octree.cpp$(ObjectSuffix) $(IntermediateDirectory)/octree_OctreeRenderNode.cpp$(ObjectSuffix) $(IntermediateDirectory)/md5parser_md5.cpp$(ObjectSuffix) $(IntermediateDirectory)/md5parser_md5Model.cpp$(ObjectSuffix) $(IntermediateDirectory)/owcmn_EncodeCommon.cpp$(ObjectSuffix) $(IntermediateDirectory)/owcmn_owcmn.cpp$(ObjectSuffix) $(IntermediateDirectory)/owcmn_resources.cpp$(ObjectSuffix) $(IntermediateDirectory)/algorithm_md5.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/buffer_buffer.cpp$(ObjectSuffix) $(IntermediateDirectory)/memory_memory.cpp$(ObjectSuffix) $(IntermediateDirectory)/owfile_owfile.cpp$(ObjectSuffix) $(IntermediateDirectory)/owZip_owZip.cpp$(ObjectSuffix) $(IntermediateDirectory)/package_owPackage.cpp$(ObjectSuffix) $(IntermediateDirectory)/package_package_common.cpp$(ObjectSuffix) $(IntermediateDirectory)/settings_settings.cpp$(ObjectSuffix) $(IntermediateDirectory)/audio_owAudio.cpp$(ObjectSuffix) $(IntermediateDirectory)/audio_owAEPlayer.cpp$(ObjectSuffix) $(IntermediateDirectory)/renderer_TextRenderer.cpp$(ObjectSuffix) \
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
	@$(MakeDirCommand) "$(BuildDir)/$(ProjectName)/Release"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "$(BuildDir)/$(ProjectName)/Release"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/scene_GameScene.cpp$(ObjectSuffix): scene/GameScene.cpp $(IntermediateDirectory)/scene_GameScene.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/core/scene/GameScene.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/scene_GameScene.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/scene_GameScene.cpp$(DependSuffix): scene/GameScene.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/scene_GameScene.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/scene_GameScene.cpp$(DependSuffix) -MM "scene/GameScene.cpp"

$(IntermediateDirectory)/scene_GameScene.cpp$(PreprocessSuffix): scene/GameScene.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/scene_GameScene.cpp$(PreprocessSuffix) "scene/GameScene.cpp"

$(IntermediateDirectory)/scene_SceneObject.cpp$(ObjectSuffix): scene/SceneObject.cpp $(IntermediateDirectory)/scene_SceneObject.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/core/scene/SceneObject.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/scene_SceneObject.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/scene_SceneObject.cpp$(DependSuffix): scene/SceneObject.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/scene_SceneObject.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/scene_SceneObject.cpp$(DependSuffix) -MM "scene/SceneObject.cpp"

$(IntermediateDirectory)/scene_SceneObject.cpp$(PreprocessSuffix): scene/SceneObject.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/scene_SceneObject.cpp$(PreprocessSuffix) "scene/SceneObject.cpp"

$(IntermediateDirectory)/model_BasicModel.cpp$(ObjectSuffix): model/BasicModel.cpp $(IntermediateDirectory)/model_BasicModel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/core/model/BasicModel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/model_BasicModel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/model_BasicModel.cpp$(DependSuffix): model/BasicModel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/model_BasicModel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/model_BasicModel.cpp$(DependSuffix) -MM "model/BasicModel.cpp"

$(IntermediateDirectory)/model_BasicModel.cpp$(PreprocessSuffix): model/BasicModel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/model_BasicModel.cpp$(PreprocessSuffix) "model/BasicModel.cpp"

$(IntermediateDirectory)/model_MD5Model.cpp$(ObjectSuffix): model/MD5Model.cpp $(IntermediateDirectory)/model_MD5Model.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/core/model/MD5Model.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/model_MD5Model.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/model_MD5Model.cpp$(DependSuffix): model/MD5Model.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/model_MD5Model.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/model_MD5Model.cpp$(DependSuffix) -MM "model/MD5Model.cpp"

$(IntermediateDirectory)/model_MD5Model.cpp$(PreprocessSuffix): model/MD5Model.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/model_MD5Model.cpp$(PreprocessSuffix) "model/MD5Model.cpp"

$(IntermediateDirectory)/model_models.cpp$(ObjectSuffix): model/models.cpp $(IntermediateDirectory)/model_models.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/core/model/models.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/model_models.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/model_models.cpp$(DependSuffix): model/models.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/model_models.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/model_models.cpp$(DependSuffix) -MM "model/models.cpp"

$(IntermediateDirectory)/model_models.cpp$(PreprocessSuffix): model/models.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/model_models.cpp$(PreprocessSuffix) "model/models.cpp"

$(IntermediateDirectory)/math_Camera.cpp$(ObjectSuffix): math/Camera.cpp $(IntermediateDirectory)/math_Camera.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/core/math/Camera.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/math_Camera.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/math_Camera.cpp$(DependSuffix): math/Camera.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/math_Camera.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/math_Camera.cpp$(DependSuffix) -MM "math/Camera.cpp"

$(IntermediateDirectory)/math_Camera.cpp$(PreprocessSuffix): math/Camera.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/math_Camera.cpp$(PreprocessSuffix) "math/Camera.cpp"

$(IntermediateDirectory)/math_Variance.cpp$(ObjectSuffix): math/Variance.cpp $(IntermediateDirectory)/math_Variance.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/core/math/Variance.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/math_Variance.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/math_Variance.cpp$(DependSuffix): math/Variance.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/math_Variance.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/math_Variance.cpp$(DependSuffix) -MM "math/Variance.cpp"

$(IntermediateDirectory)/math_Variance.cpp$(PreprocessSuffix): math/Variance.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/math_Variance.cpp$(PreprocessSuffix) "math/Variance.cpp"

$(IntermediateDirectory)/core_BufferOGL.cpp$(ObjectSuffix): core/BufferOGL.cpp $(IntermediateDirectory)/core_BufferOGL.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/core/core/BufferOGL.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_BufferOGL.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_BufferOGL.cpp$(DependSuffix): core/BufferOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_BufferOGL.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/core_BufferOGL.cpp$(DependSuffix) -MM "core/BufferOGL.cpp"

$(IntermediateDirectory)/core_BufferOGL.cpp$(PreprocessSuffix): core/BufferOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_BufferOGL.cpp$(PreprocessSuffix) "core/BufferOGL.cpp"

$(IntermediateDirectory)/core_DepthStencilOGL.cpp$(ObjectSuffix): core/DepthStencilOGL.cpp $(IntermediateDirectory)/core_DepthStencilOGL.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/core/core/DepthStencilOGL.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_DepthStencilOGL.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_DepthStencilOGL.cpp$(DependSuffix): core/DepthStencilOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_DepthStencilOGL.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/core_DepthStencilOGL.cpp$(DependSuffix) -MM "core/DepthStencilOGL.cpp"

$(IntermediateDirectory)/core_DepthStencilOGL.cpp$(PreprocessSuffix): core/DepthStencilOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_DepthStencilOGL.cpp$(PreprocessSuffix) "core/DepthStencilOGL.cpp"

$(IntermediateDirectory)/core_EffectOGL.cpp$(ObjectSuffix): core/EffectOGL.cpp $(IntermediateDirectory)/core_EffectOGL.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/core/core/EffectOGL.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_EffectOGL.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_EffectOGL.cpp$(DependSuffix): core/EffectOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_EffectOGL.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/core_EffectOGL.cpp$(DependSuffix) -MM "core/EffectOGL.cpp"

$(IntermediateDirectory)/core_EffectOGL.cpp$(PreprocessSuffix): core/EffectOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_EffectOGL.cpp$(PreprocessSuffix) "core/EffectOGL.cpp"

$(IntermediateDirectory)/core_Image.cpp$(ObjectSuffix): core/Image.cpp $(IntermediateDirectory)/core_Image.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/core/core/Image.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_Image.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_Image.cpp$(DependSuffix): core/Image.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_Image.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/core_Image.cpp$(DependSuffix) -MM "core/Image.cpp"

$(IntermediateDirectory)/core_Image.cpp$(PreprocessSuffix): core/Image.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_Image.cpp$(PreprocessSuffix) "core/Image.cpp"

$(IntermediateDirectory)/core_RenderPipelineOGL.cpp$(ObjectSuffix): core/RenderPipelineOGL.cpp $(IntermediateDirectory)/core_RenderPipelineOGL.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/core/core/RenderPipelineOGL.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_RenderPipelineOGL.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_RenderPipelineOGL.cpp$(DependSuffix): core/RenderPipelineOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_RenderPipelineOGL.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/core_RenderPipelineOGL.cpp$(DependSuffix) -MM "core/RenderPipelineOGL.cpp"

$(IntermediateDirectory)/core_RenderPipelineOGL.cpp$(PreprocessSuffix): core/RenderPipelineOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_RenderPipelineOGL.cpp$(PreprocessSuffix) "core/RenderPipelineOGL.cpp"

$(IntermediateDirectory)/core_RenderTargetOGL.cpp$(ObjectSuffix): core/RenderTargetOGL.cpp $(IntermediateDirectory)/core_RenderTargetOGL.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/core/core/RenderTargetOGL.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_RenderTargetOGL.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_RenderTargetOGL.cpp$(DependSuffix): core/RenderTargetOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_RenderTargetOGL.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/core_RenderTargetOGL.cpp$(DependSuffix) -MM "core/RenderTargetOGL.cpp"

$(IntermediateDirectory)/core_RenderTargetOGL.cpp$(PreprocessSuffix): core/RenderTargetOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_RenderTargetOGL.cpp$(PreprocessSuffix) "core/RenderTargetOGL.cpp"

$(IntermediateDirectory)/core_ShaderOGL.cpp$(ObjectSuffix): core/ShaderOGL.cpp $(IntermediateDirectory)/core_ShaderOGL.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/core/core/ShaderOGL.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_ShaderOGL.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_ShaderOGL.cpp$(DependSuffix): core/ShaderOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_ShaderOGL.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/core_ShaderOGL.cpp$(DependSuffix) -MM "core/ShaderOGL.cpp"

$(IntermediateDirectory)/core_ShaderOGL.cpp$(PreprocessSuffix): core/ShaderOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_ShaderOGL.cpp$(PreprocessSuffix) "core/ShaderOGL.cpp"

$(IntermediateDirectory)/core_TexOGL.cpp$(ObjectSuffix): core/TexOGL.cpp $(IntermediateDirectory)/core_TexOGL.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/core/core/TexOGL.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_TexOGL.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_TexOGL.cpp$(DependSuffix): core/TexOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_TexOGL.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/core_TexOGL.cpp$(DependSuffix) -MM "core/TexOGL.cpp"

$(IntermediateDirectory)/core_TexOGL.cpp$(PreprocessSuffix): core/TexOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_TexOGL.cpp$(PreprocessSuffix) "core/TexOGL.cpp"

$(IntermediateDirectory)/app_AppDelegate.cpp$(ObjectSuffix): app/AppDelegate.cpp $(IntermediateDirectory)/app_AppDelegate.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/core/app/AppDelegate.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/app_AppDelegate.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/app_AppDelegate.cpp$(DependSuffix): app/AppDelegate.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/app_AppDelegate.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/app_AppDelegate.cpp$(DependSuffix) -MM "app/AppDelegate.cpp"

$(IntermediateDirectory)/app_AppDelegate.cpp$(PreprocessSuffix): app/AppDelegate.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/app_AppDelegate.cpp$(PreprocessSuffix) "app/AppDelegate.cpp"

$(IntermediateDirectory)/app_OpenGLViewController.cpp$(ObjectSuffix): app/OpenGLViewController.cpp $(IntermediateDirectory)/app_OpenGLViewController.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/core/app/OpenGLViewController.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/app_OpenGLViewController.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/app_OpenGLViewController.cpp$(DependSuffix): app/OpenGLViewController.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/app_OpenGLViewController.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/app_OpenGLViewController.cpp$(DependSuffix) -MM "app/OpenGLViewController.cpp"

$(IntermediateDirectory)/app_OpenGLViewController.cpp$(PreprocessSuffix): app/OpenGLViewController.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/app_OpenGLViewController.cpp$(PreprocessSuffix) "app/OpenGLViewController.cpp"

$(IntermediateDirectory)/event_MouseEvent.cpp$(ObjectSuffix): event/MouseEvent.cpp $(IntermediateDirectory)/event_MouseEvent.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/core/event/MouseEvent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/event_MouseEvent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/event_MouseEvent.cpp$(DependSuffix): event/MouseEvent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/event_MouseEvent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/event_MouseEvent.cpp$(DependSuffix) -MM "event/MouseEvent.cpp"

$(IntermediateDirectory)/event_MouseEvent.cpp$(PreprocessSuffix): event/MouseEvent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/event_MouseEvent.cpp$(PreprocessSuffix) "event/MouseEvent.cpp"

$(IntermediateDirectory)/gui_Label.cpp$(ObjectSuffix): gui/Label.cpp $(IntermediateDirectory)/gui_Label.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/core/gui/Label.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gui_Label.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_Label.cpp$(DependSuffix): gui/Label.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_Label.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_Label.cpp$(DependSuffix) -MM "gui/Label.cpp"

$(IntermediateDirectory)/gui_Label.cpp$(PreprocessSuffix): gui/Label.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_Label.cpp$(PreprocessSuffix) "gui/Label.cpp"

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/core/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/audioManager_AudioManager.cpp$(ObjectSuffix): audioManager/AudioManager.cpp $(IntermediateDirectory)/audioManager_AudioManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/core/audioManager/AudioManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/audioManager_AudioManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/audioManager_AudioManager.cpp$(DependSuffix): audioManager/AudioManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/audioManager_AudioManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/audioManager_AudioManager.cpp$(DependSuffix) -MM "audioManager/AudioManager.cpp"

$(IntermediateDirectory)/audioManager_AudioManager.cpp$(PreprocessSuffix): audioManager/AudioManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/audioManager_AudioManager.cpp$(PreprocessSuffix) "audioManager/AudioManager.cpp"

$(IntermediateDirectory)/aabb_aabb.cpp$(ObjectSuffix): scene/aabb/aabb.cpp $(IntermediateDirectory)/aabb_aabb.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/core/scene/aabb/aabb.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/aabb_aabb.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/aabb_aabb.cpp$(DependSuffix): scene/aabb/aabb.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/aabb_aabb.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/aabb_aabb.cpp$(DependSuffix) -MM "scene/aabb/aabb.cpp"

$(IntermediateDirectory)/aabb_aabb.cpp$(PreprocessSuffix): scene/aabb/aabb.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/aabb_aabb.cpp$(PreprocessSuffix) "scene/aabb/aabb.cpp"

$(IntermediateDirectory)/octree_Octree.cpp$(ObjectSuffix): scene/octree/Octree.cpp $(IntermediateDirectory)/octree_Octree.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/core/scene/octree/Octree.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/octree_Octree.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/octree_Octree.cpp$(DependSuffix): scene/octree/Octree.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/octree_Octree.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/octree_Octree.cpp$(DependSuffix) -MM "scene/octree/Octree.cpp"

$(IntermediateDirectory)/octree_Octree.cpp$(PreprocessSuffix): scene/octree/Octree.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/octree_Octree.cpp$(PreprocessSuffix) "scene/octree/Octree.cpp"

$(IntermediateDirectory)/octree_OctreeRenderNode.cpp$(ObjectSuffix): scene/octree/OctreeRenderNode.cpp $(IntermediateDirectory)/octree_OctreeRenderNode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/core/scene/octree/OctreeRenderNode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/octree_OctreeRenderNode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/octree_OctreeRenderNode.cpp$(DependSuffix): scene/octree/OctreeRenderNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/octree_OctreeRenderNode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/octree_OctreeRenderNode.cpp$(DependSuffix) -MM "scene/octree/OctreeRenderNode.cpp"

$(IntermediateDirectory)/octree_OctreeRenderNode.cpp$(PreprocessSuffix): scene/octree/OctreeRenderNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/octree_OctreeRenderNode.cpp$(PreprocessSuffix) "scene/octree/OctreeRenderNode.cpp"

$(IntermediateDirectory)/md5parser_md5.cpp$(ObjectSuffix): model/md5parser/md5.cpp $(IntermediateDirectory)/md5parser_md5.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/core/model/md5parser/md5.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/md5parser_md5.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/md5parser_md5.cpp$(DependSuffix): model/md5parser/md5.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/md5parser_md5.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/md5parser_md5.cpp$(DependSuffix) -MM "model/md5parser/md5.cpp"

$(IntermediateDirectory)/md5parser_md5.cpp$(PreprocessSuffix): model/md5parser/md5.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/md5parser_md5.cpp$(PreprocessSuffix) "model/md5parser/md5.cpp"

$(IntermediateDirectory)/md5parser_md5Model.cpp$(ObjectSuffix): model/md5parser/md5Model.cpp $(IntermediateDirectory)/md5parser_md5Model.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/core/model/md5parser/md5Model.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/md5parser_md5Model.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/md5parser_md5Model.cpp$(DependSuffix): model/md5parser/md5Model.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/md5parser_md5Model.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/md5parser_md5Model.cpp$(DependSuffix) -MM "model/md5parser/md5Model.cpp"

$(IntermediateDirectory)/md5parser_md5Model.cpp$(PreprocessSuffix): model/md5parser/md5Model.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/md5parser_md5Model.cpp$(PreprocessSuffix) "model/md5parser/md5Model.cpp"

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

$(IntermediateDirectory)/owcmn_resources.cpp$(ObjectSuffix): ../ow/owcmn/resources.cpp $(IntermediateDirectory)/owcmn_resources.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/ow/owcmn/resources.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/owcmn_resources.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/owcmn_resources.cpp$(DependSuffix): ../ow/owcmn/resources.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/owcmn_resources.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/owcmn_resources.cpp$(DependSuffix) -MM "../ow/owcmn/resources.cpp"

$(IntermediateDirectory)/owcmn_resources.cpp$(PreprocessSuffix): ../ow/owcmn/resources.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/owcmn_resources.cpp$(PreprocessSuffix) "../ow/owcmn/resources.cpp"

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

$(IntermediateDirectory)/owZip_owZip.cpp$(ObjectSuffix): ../ow/owZip/owZip.cpp $(IntermediateDirectory)/owZip_owZip.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/ow/owZip/owZip.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/owZip_owZip.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/owZip_owZip.cpp$(DependSuffix): ../ow/owZip/owZip.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/owZip_owZip.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/owZip_owZip.cpp$(DependSuffix) -MM "../ow/owZip/owZip.cpp"

$(IntermediateDirectory)/owZip_owZip.cpp$(PreprocessSuffix): ../ow/owZip/owZip.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/owZip_owZip.cpp$(PreprocessSuffix) "../ow/owZip/owZip.cpp"

$(IntermediateDirectory)/package_owPackage.cpp$(ObjectSuffix): ../ow/package/owPackage.cpp $(IntermediateDirectory)/package_owPackage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/ow/package/owPackage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/package_owPackage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/package_owPackage.cpp$(DependSuffix): ../ow/package/owPackage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/package_owPackage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/package_owPackage.cpp$(DependSuffix) -MM "../ow/package/owPackage.cpp"

$(IntermediateDirectory)/package_owPackage.cpp$(PreprocessSuffix): ../ow/package/owPackage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/package_owPackage.cpp$(PreprocessSuffix) "../ow/package/owPackage.cpp"

$(IntermediateDirectory)/package_package_common.cpp$(ObjectSuffix): ../ow/package/package_common.cpp $(IntermediateDirectory)/package_package_common.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/ow/package/package_common.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/package_package_common.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/package_package_common.cpp$(DependSuffix): ../ow/package/package_common.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/package_package_common.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/package_package_common.cpp$(DependSuffix) -MM "../ow/package/package_common.cpp"

$(IntermediateDirectory)/package_package_common.cpp$(PreprocessSuffix): ../ow/package/package_common.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/package_package_common.cpp$(PreprocessSuffix) "../ow/package/package_common.cpp"

$(IntermediateDirectory)/settings_settings.cpp$(ObjectSuffix): ../ow/settings/settings.cpp $(IntermediateDirectory)/settings_settings.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/ow/settings/settings.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/settings_settings.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/settings_settings.cpp$(DependSuffix): ../ow/settings/settings.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/settings_settings.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/settings_settings.cpp$(DependSuffix) -MM "../ow/settings/settings.cpp"

$(IntermediateDirectory)/settings_settings.cpp$(PreprocessSuffix): ../ow/settings/settings.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/settings_settings.cpp$(PreprocessSuffix) "../ow/settings/settings.cpp"

$(IntermediateDirectory)/audio_owAudio.cpp$(ObjectSuffix): ../ow/audio/owAudio.cpp $(IntermediateDirectory)/audio_owAudio.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/ow/audio/owAudio.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/audio_owAudio.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/audio_owAudio.cpp$(DependSuffix): ../ow/audio/owAudio.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/audio_owAudio.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/audio_owAudio.cpp$(DependSuffix) -MM "../ow/audio/owAudio.cpp"

$(IntermediateDirectory)/audio_owAudio.cpp$(PreprocessSuffix): ../ow/audio/owAudio.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/audio_owAudio.cpp$(PreprocessSuffix) "../ow/audio/owAudio.cpp"

$(IntermediateDirectory)/audio_owAEPlayer.cpp$(ObjectSuffix): ../ow/audio/owAEPlayer.cpp $(IntermediateDirectory)/audio_owAEPlayer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/ow/audio/owAEPlayer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/audio_owAEPlayer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/audio_owAEPlayer.cpp$(DependSuffix): ../ow/audio/owAEPlayer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/audio_owAEPlayer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/audio_owAEPlayer.cpp$(DependSuffix) -MM "../ow/audio/owAEPlayer.cpp"

$(IntermediateDirectory)/audio_owAEPlayer.cpp$(PreprocessSuffix): ../ow/audio/owAEPlayer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/audio_owAEPlayer.cpp$(PreprocessSuffix) "../ow/audio/owAEPlayer.cpp"

$(IntermediateDirectory)/renderer_TextRenderer.cpp$(ObjectSuffix): core/renderer/TextRenderer.cpp $(IntermediateDirectory)/renderer_TextRenderer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/core/core/renderer/TextRenderer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/renderer_TextRenderer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/renderer_TextRenderer.cpp$(DependSuffix): core/renderer/TextRenderer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/renderer_TextRenderer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/renderer_TextRenderer.cpp$(DependSuffix) -MM "core/renderer/TextRenderer.cpp"

$(IntermediateDirectory)/renderer_TextRenderer.cpp$(PreprocessSuffix): core/renderer/TextRenderer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/renderer_TextRenderer.cpp$(PreprocessSuffix) "core/renderer/TextRenderer.cpp"

$(IntermediateDirectory)/log_logger.cpp$(ObjectSuffix): ../ow/owcmn/log/logger.cpp $(IntermediateDirectory)/log_logger.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/gits/graphics/ow/owcmn/log/logger.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/log_logger.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/log_logger.cpp$(DependSuffix): ../ow/owcmn/log/logger.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/log_logger.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/log_logger.cpp$(DependSuffix) -MM "../ow/owcmn/log/logger.cpp"

$(IntermediateDirectory)/log_logger.cpp$(PreprocessSuffix): ../ow/owcmn/log/logger.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/log_logger.cpp$(PreprocessSuffix) "../ow/owcmn/log/logger.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(BuildDir)/$(ProjectName)/Release/


