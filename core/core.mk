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
Date                   :=07/11/2015
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
OutputFile             :=$(BuildDir)/$(ProjectName)/$(ProjectName)_debug
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="core.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=F:/tdmgcc/bin/windres.exe
LinkOptions            :=  -lglew32 -lglfw3 -lpng -lz -lgdi32 -lopengl32 -lfreetype -liconv -lopenal32 -logg.dll -lvorbisfile.dll
IncludePath            := $(IncludeSwitch)F:/tdmgcclib/include $(IncludeSwitch)F:/tdmgcclib/include/freetype $(IncludeSwitch)E:/projects/graphics/ow  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)../ow $(IncludeSwitch)../ow/script 
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
Objects0=$(IntermediateDirectory)/scene_GameScene.cpp$(ObjectSuffix) $(IntermediateDirectory)/scene_SceneObject.cpp$(ObjectSuffix) $(IntermediateDirectory)/model_BasicModel.cpp$(ObjectSuffix) $(IntermediateDirectory)/model_MD5Model.cpp$(ObjectSuffix) $(IntermediateDirectory)/model_models.cpp$(ObjectSuffix) $(IntermediateDirectory)/math_Camera.cpp$(ObjectSuffix) $(IntermediateDirectory)/math_Variance.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_BufferOGL.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_DepthStencilOGL.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_EffectOGL.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/core_Image.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_RenderPipelineOGL.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_RenderTargetOGL.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_ShaderOGL.cpp$(ObjectSuffix) $(IntermediateDirectory)/core_TexOGL.cpp$(ObjectSuffix) $(IntermediateDirectory)/app_AppDelegate.cpp$(ObjectSuffix) $(IntermediateDirectory)/app_OpenGLViewController.cpp$(ObjectSuffix) $(IntermediateDirectory)/event_MouseEvent.cpp$(ObjectSuffix) $(IntermediateDirectory)/gui_Label.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/audioManager_AudioManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/owcmn_owcmn.cpp$(ObjectSuffix) $(IntermediateDirectory)/owcmn_owstring.cpp$(ObjectSuffix) $(IntermediateDirectory)/owcmn_resources.cpp$(ObjectSuffix) $(IntermediateDirectory)/algorithm_md5.cpp$(ObjectSuffix) $(IntermediateDirectory)/archive_owArchive.cpp$(ObjectSuffix) $(IntermediateDirectory)/audio_owAEPlayer.cpp$(ObjectSuffix) $(IntermediateDirectory)/audio_owAudio.cpp$(ObjectSuffix) $(IntermediateDirectory)/buffer_buffer.cpp$(ObjectSuffix) $(IntermediateDirectory)/excel_excel.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/excel_excel_def_imp.cpp$(ObjectSuffix) $(IntermediateDirectory)/memory_memory.cpp$(ObjectSuffix) $(IntermediateDirectory)/owZip_owZip.cpp$(ObjectSuffix) $(IntermediateDirectory)/owfile_owfile.cpp$(ObjectSuffix) $(IntermediateDirectory)/package_owPackage.cpp$(ObjectSuffix) $(IntermediateDirectory)/package_package_common.cpp$(ObjectSuffix) $(IntermediateDirectory)/aabb_aabb.cpp$(ObjectSuffix) $(IntermediateDirectory)/octree_Octree.cpp$(ObjectSuffix) $(IntermediateDirectory)/octree_OctreeRenderNode.cpp$(ObjectSuffix) $(IntermediateDirectory)/md5parser_md5.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/md5parser_md5Model.cpp$(ObjectSuffix) $(IntermediateDirectory)/renderer_TextRenderer.cpp$(ObjectSuffix) 

Objects1=$(IntermediateDirectory)/lua_lapi.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lauxlib.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lbaselib.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lbitlib.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lcode.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lcorolib.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lctype.c$(ObjectSuffix) $(IntermediateDirectory)/lua_ldblib.c$(ObjectSuffix) \
	$(IntermediateDirectory)/lua_ldebug.c$(ObjectSuffix) $(IntermediateDirectory)/lua_ldo.c$(ObjectSuffix) $(IntermediateDirectory)/lua_ldump.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lfunc.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lgc.c$(ObjectSuffix) $(IntermediateDirectory)/lua_linit.c$(ObjectSuffix) $(IntermediateDirectory)/lua_liolib.c$(ObjectSuffix) $(IntermediateDirectory)/lua_llex.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lmathlib.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lmem.c$(ObjectSuffix) \
	$(IntermediateDirectory)/lua_loadlib.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lobject.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lopcodes.c$(ObjectSuffix) $(IntermediateDirectory)/lua_loslib.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lparser.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lstate.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lstring.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lstrlib.c$(ObjectSuffix) $(IntermediateDirectory)/lua_ltable.c$(ObjectSuffix) $(IntermediateDirectory)/lua_ltablib.c$(ObjectSuffix) \
	$(IntermediateDirectory)/lua_ltm.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lua.c$(ObjectSuffix) $(IntermediateDirectory)/lua_luac.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lundump.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lvm.c$(ObjectSuffix) $(IntermediateDirectory)/lua_lzio.c$(ObjectSuffix) $(IntermediateDirectory)/scriptEngine_ScriptEngine.cpp$(ObjectSuffix) $(IntermediateDirectory)/log_logger.cpp$(ObjectSuffix) 



Objects=$(Objects0) $(Objects1) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	@echo $(Objects1) >> $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "$(BuildDir)/$(ProjectName)/Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "$(BuildDir)/$(ProjectName)/Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/scene_GameScene.cpp$(ObjectSuffix): scene/GameScene.cpp $(IntermediateDirectory)/scene_GameScene.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/scene/GameScene.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/scene_GameScene.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/scene_GameScene.cpp$(DependSuffix): scene/GameScene.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/scene_GameScene.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/scene_GameScene.cpp$(DependSuffix) -MM "scene/GameScene.cpp"

$(IntermediateDirectory)/scene_GameScene.cpp$(PreprocessSuffix): scene/GameScene.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/scene_GameScene.cpp$(PreprocessSuffix) "scene/GameScene.cpp"

$(IntermediateDirectory)/scene_SceneObject.cpp$(ObjectSuffix): scene/SceneObject.cpp $(IntermediateDirectory)/scene_SceneObject.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/scene/SceneObject.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/scene_SceneObject.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/scene_SceneObject.cpp$(DependSuffix): scene/SceneObject.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/scene_SceneObject.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/scene_SceneObject.cpp$(DependSuffix) -MM "scene/SceneObject.cpp"

$(IntermediateDirectory)/scene_SceneObject.cpp$(PreprocessSuffix): scene/SceneObject.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/scene_SceneObject.cpp$(PreprocessSuffix) "scene/SceneObject.cpp"

$(IntermediateDirectory)/model_BasicModel.cpp$(ObjectSuffix): model/BasicModel.cpp $(IntermediateDirectory)/model_BasicModel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/model/BasicModel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/model_BasicModel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/model_BasicModel.cpp$(DependSuffix): model/BasicModel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/model_BasicModel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/model_BasicModel.cpp$(DependSuffix) -MM "model/BasicModel.cpp"

$(IntermediateDirectory)/model_BasicModel.cpp$(PreprocessSuffix): model/BasicModel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/model_BasicModel.cpp$(PreprocessSuffix) "model/BasicModel.cpp"

$(IntermediateDirectory)/model_MD5Model.cpp$(ObjectSuffix): model/MD5Model.cpp $(IntermediateDirectory)/model_MD5Model.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/model/MD5Model.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/model_MD5Model.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/model_MD5Model.cpp$(DependSuffix): model/MD5Model.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/model_MD5Model.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/model_MD5Model.cpp$(DependSuffix) -MM "model/MD5Model.cpp"

$(IntermediateDirectory)/model_MD5Model.cpp$(PreprocessSuffix): model/MD5Model.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/model_MD5Model.cpp$(PreprocessSuffix) "model/MD5Model.cpp"

$(IntermediateDirectory)/model_models.cpp$(ObjectSuffix): model/models.cpp $(IntermediateDirectory)/model_models.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/model/models.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/model_models.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/model_models.cpp$(DependSuffix): model/models.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/model_models.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/model_models.cpp$(DependSuffix) -MM "model/models.cpp"

$(IntermediateDirectory)/model_models.cpp$(PreprocessSuffix): model/models.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/model_models.cpp$(PreprocessSuffix) "model/models.cpp"

$(IntermediateDirectory)/math_Camera.cpp$(ObjectSuffix): math/Camera.cpp $(IntermediateDirectory)/math_Camera.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/math/Camera.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/math_Camera.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/math_Camera.cpp$(DependSuffix): math/Camera.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/math_Camera.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/math_Camera.cpp$(DependSuffix) -MM "math/Camera.cpp"

$(IntermediateDirectory)/math_Camera.cpp$(PreprocessSuffix): math/Camera.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/math_Camera.cpp$(PreprocessSuffix) "math/Camera.cpp"

$(IntermediateDirectory)/math_Variance.cpp$(ObjectSuffix): math/Variance.cpp $(IntermediateDirectory)/math_Variance.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/math/Variance.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/math_Variance.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/math_Variance.cpp$(DependSuffix): math/Variance.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/math_Variance.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/math_Variance.cpp$(DependSuffix) -MM "math/Variance.cpp"

$(IntermediateDirectory)/math_Variance.cpp$(PreprocessSuffix): math/Variance.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/math_Variance.cpp$(PreprocessSuffix) "math/Variance.cpp"

$(IntermediateDirectory)/core_BufferOGL.cpp$(ObjectSuffix): core/BufferOGL.cpp $(IntermediateDirectory)/core_BufferOGL.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/core/BufferOGL.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_BufferOGL.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_BufferOGL.cpp$(DependSuffix): core/BufferOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_BufferOGL.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/core_BufferOGL.cpp$(DependSuffix) -MM "core/BufferOGL.cpp"

$(IntermediateDirectory)/core_BufferOGL.cpp$(PreprocessSuffix): core/BufferOGL.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_BufferOGL.cpp$(PreprocessSuffix) "core/BufferOGL.cpp"

$(IntermediateDirectory)/core_DepthStencilOGL.cpp$(ObjectSuffix): core/DepthStencilOGL.cpp $(IntermediateDirectory)/core_DepthStencilOGL.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/core/DepthStencilOGL.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_DepthStencilOGL.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_DepthStencilOGL.cpp$(DependSuffix): core/DepthStencilOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_DepthStencilOGL.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/core_DepthStencilOGL.cpp$(DependSuffix) -MM "core/DepthStencilOGL.cpp"

$(IntermediateDirectory)/core_DepthStencilOGL.cpp$(PreprocessSuffix): core/DepthStencilOGL.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_DepthStencilOGL.cpp$(PreprocessSuffix) "core/DepthStencilOGL.cpp"

$(IntermediateDirectory)/core_EffectOGL.cpp$(ObjectSuffix): core/EffectOGL.cpp $(IntermediateDirectory)/core_EffectOGL.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/core/EffectOGL.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_EffectOGL.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_EffectOGL.cpp$(DependSuffix): core/EffectOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_EffectOGL.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/core_EffectOGL.cpp$(DependSuffix) -MM "core/EffectOGL.cpp"

$(IntermediateDirectory)/core_EffectOGL.cpp$(PreprocessSuffix): core/EffectOGL.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_EffectOGL.cpp$(PreprocessSuffix) "core/EffectOGL.cpp"

$(IntermediateDirectory)/core_Image.cpp$(ObjectSuffix): core/Image.cpp $(IntermediateDirectory)/core_Image.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/core/Image.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_Image.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_Image.cpp$(DependSuffix): core/Image.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_Image.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/core_Image.cpp$(DependSuffix) -MM "core/Image.cpp"

$(IntermediateDirectory)/core_Image.cpp$(PreprocessSuffix): core/Image.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_Image.cpp$(PreprocessSuffix) "core/Image.cpp"

$(IntermediateDirectory)/core_RenderPipelineOGL.cpp$(ObjectSuffix): core/RenderPipelineOGL.cpp $(IntermediateDirectory)/core_RenderPipelineOGL.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/core/RenderPipelineOGL.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_RenderPipelineOGL.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_RenderPipelineOGL.cpp$(DependSuffix): core/RenderPipelineOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_RenderPipelineOGL.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/core_RenderPipelineOGL.cpp$(DependSuffix) -MM "core/RenderPipelineOGL.cpp"

$(IntermediateDirectory)/core_RenderPipelineOGL.cpp$(PreprocessSuffix): core/RenderPipelineOGL.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_RenderPipelineOGL.cpp$(PreprocessSuffix) "core/RenderPipelineOGL.cpp"

$(IntermediateDirectory)/core_RenderTargetOGL.cpp$(ObjectSuffix): core/RenderTargetOGL.cpp $(IntermediateDirectory)/core_RenderTargetOGL.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/core/RenderTargetOGL.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_RenderTargetOGL.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_RenderTargetOGL.cpp$(DependSuffix): core/RenderTargetOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_RenderTargetOGL.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/core_RenderTargetOGL.cpp$(DependSuffix) -MM "core/RenderTargetOGL.cpp"

$(IntermediateDirectory)/core_RenderTargetOGL.cpp$(PreprocessSuffix): core/RenderTargetOGL.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_RenderTargetOGL.cpp$(PreprocessSuffix) "core/RenderTargetOGL.cpp"

$(IntermediateDirectory)/core_ShaderOGL.cpp$(ObjectSuffix): core/ShaderOGL.cpp $(IntermediateDirectory)/core_ShaderOGL.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/core/ShaderOGL.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_ShaderOGL.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_ShaderOGL.cpp$(DependSuffix): core/ShaderOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_ShaderOGL.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/core_ShaderOGL.cpp$(DependSuffix) -MM "core/ShaderOGL.cpp"

$(IntermediateDirectory)/core_ShaderOGL.cpp$(PreprocessSuffix): core/ShaderOGL.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_ShaderOGL.cpp$(PreprocessSuffix) "core/ShaderOGL.cpp"

$(IntermediateDirectory)/core_TexOGL.cpp$(ObjectSuffix): core/TexOGL.cpp $(IntermediateDirectory)/core_TexOGL.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/core/TexOGL.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_TexOGL.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_TexOGL.cpp$(DependSuffix): core/TexOGL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_TexOGL.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/core_TexOGL.cpp$(DependSuffix) -MM "core/TexOGL.cpp"

$(IntermediateDirectory)/core_TexOGL.cpp$(PreprocessSuffix): core/TexOGL.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_TexOGL.cpp$(PreprocessSuffix) "core/TexOGL.cpp"

$(IntermediateDirectory)/app_AppDelegate.cpp$(ObjectSuffix): app/AppDelegate.cpp $(IntermediateDirectory)/app_AppDelegate.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/app/AppDelegate.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/app_AppDelegate.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/app_AppDelegate.cpp$(DependSuffix): app/AppDelegate.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/app_AppDelegate.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/app_AppDelegate.cpp$(DependSuffix) -MM "app/AppDelegate.cpp"

$(IntermediateDirectory)/app_AppDelegate.cpp$(PreprocessSuffix): app/AppDelegate.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/app_AppDelegate.cpp$(PreprocessSuffix) "app/AppDelegate.cpp"

$(IntermediateDirectory)/app_OpenGLViewController.cpp$(ObjectSuffix): app/OpenGLViewController.cpp $(IntermediateDirectory)/app_OpenGLViewController.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/app/OpenGLViewController.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/app_OpenGLViewController.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/app_OpenGLViewController.cpp$(DependSuffix): app/OpenGLViewController.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/app_OpenGLViewController.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/app_OpenGLViewController.cpp$(DependSuffix) -MM "app/OpenGLViewController.cpp"

$(IntermediateDirectory)/app_OpenGLViewController.cpp$(PreprocessSuffix): app/OpenGLViewController.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/app_OpenGLViewController.cpp$(PreprocessSuffix) "app/OpenGLViewController.cpp"

$(IntermediateDirectory)/event_MouseEvent.cpp$(ObjectSuffix): event/MouseEvent.cpp $(IntermediateDirectory)/event_MouseEvent.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/event/MouseEvent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/event_MouseEvent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/event_MouseEvent.cpp$(DependSuffix): event/MouseEvent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/event_MouseEvent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/event_MouseEvent.cpp$(DependSuffix) -MM "event/MouseEvent.cpp"

$(IntermediateDirectory)/event_MouseEvent.cpp$(PreprocessSuffix): event/MouseEvent.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/event_MouseEvent.cpp$(PreprocessSuffix) "event/MouseEvent.cpp"

$(IntermediateDirectory)/gui_Label.cpp$(ObjectSuffix): gui/Label.cpp $(IntermediateDirectory)/gui_Label.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/gui/Label.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/gui_Label.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui_Label.cpp$(DependSuffix): gui/Label.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/gui_Label.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/gui_Label.cpp$(DependSuffix) -MM "gui/Label.cpp"

$(IntermediateDirectory)/gui_Label.cpp$(PreprocessSuffix): gui/Label.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/gui_Label.cpp$(PreprocessSuffix) "gui/Label.cpp"

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/audioManager_AudioManager.cpp$(ObjectSuffix): audioManager/AudioManager.cpp $(IntermediateDirectory)/audioManager_AudioManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/audioManager/AudioManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/audioManager_AudioManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/audioManager_AudioManager.cpp$(DependSuffix): audioManager/AudioManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/audioManager_AudioManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/audioManager_AudioManager.cpp$(DependSuffix) -MM "audioManager/AudioManager.cpp"

$(IntermediateDirectory)/audioManager_AudioManager.cpp$(PreprocessSuffix): audioManager/AudioManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/audioManager_AudioManager.cpp$(PreprocessSuffix) "audioManager/AudioManager.cpp"

$(IntermediateDirectory)/owcmn_owcmn.cpp$(ObjectSuffix): ../ow/owcmn/owcmn.cpp $(IntermediateDirectory)/owcmn_owcmn.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/ow/owcmn/owcmn.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/owcmn_owcmn.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/owcmn_owcmn.cpp$(DependSuffix): ../ow/owcmn/owcmn.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/owcmn_owcmn.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/owcmn_owcmn.cpp$(DependSuffix) -MM "../ow/owcmn/owcmn.cpp"

$(IntermediateDirectory)/owcmn_owcmn.cpp$(PreprocessSuffix): ../ow/owcmn/owcmn.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/owcmn_owcmn.cpp$(PreprocessSuffix) "../ow/owcmn/owcmn.cpp"

$(IntermediateDirectory)/owcmn_owstring.cpp$(ObjectSuffix): ../ow/owcmn/owstring.cpp $(IntermediateDirectory)/owcmn_owstring.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/ow/owcmn/owstring.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/owcmn_owstring.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/owcmn_owstring.cpp$(DependSuffix): ../ow/owcmn/owstring.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/owcmn_owstring.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/owcmn_owstring.cpp$(DependSuffix) -MM "../ow/owcmn/owstring.cpp"

$(IntermediateDirectory)/owcmn_owstring.cpp$(PreprocessSuffix): ../ow/owcmn/owstring.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/owcmn_owstring.cpp$(PreprocessSuffix) "../ow/owcmn/owstring.cpp"

$(IntermediateDirectory)/owcmn_resources.cpp$(ObjectSuffix): ../ow/owcmn/resources.cpp $(IntermediateDirectory)/owcmn_resources.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/ow/owcmn/resources.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/owcmn_resources.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/owcmn_resources.cpp$(DependSuffix): ../ow/owcmn/resources.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/owcmn_resources.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/owcmn_resources.cpp$(DependSuffix) -MM "../ow/owcmn/resources.cpp"

$(IntermediateDirectory)/owcmn_resources.cpp$(PreprocessSuffix): ../ow/owcmn/resources.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/owcmn_resources.cpp$(PreprocessSuffix) "../ow/owcmn/resources.cpp"

$(IntermediateDirectory)/algorithm_md5.cpp$(ObjectSuffix): ../ow/algorithm/md5.cpp $(IntermediateDirectory)/algorithm_md5.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/ow/algorithm/md5.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/algorithm_md5.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/algorithm_md5.cpp$(DependSuffix): ../ow/algorithm/md5.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/algorithm_md5.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/algorithm_md5.cpp$(DependSuffix) -MM "../ow/algorithm/md5.cpp"

$(IntermediateDirectory)/algorithm_md5.cpp$(PreprocessSuffix): ../ow/algorithm/md5.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/algorithm_md5.cpp$(PreprocessSuffix) "../ow/algorithm/md5.cpp"

$(IntermediateDirectory)/archive_owArchive.cpp$(ObjectSuffix): ../ow/archive/owArchive.cpp $(IntermediateDirectory)/archive_owArchive.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/ow/archive/owArchive.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/archive_owArchive.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/archive_owArchive.cpp$(DependSuffix): ../ow/archive/owArchive.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/archive_owArchive.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/archive_owArchive.cpp$(DependSuffix) -MM "../ow/archive/owArchive.cpp"

$(IntermediateDirectory)/archive_owArchive.cpp$(PreprocessSuffix): ../ow/archive/owArchive.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/archive_owArchive.cpp$(PreprocessSuffix) "../ow/archive/owArchive.cpp"

$(IntermediateDirectory)/audio_owAEPlayer.cpp$(ObjectSuffix): ../ow/audio/owAEPlayer.cpp $(IntermediateDirectory)/audio_owAEPlayer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/ow/audio/owAEPlayer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/audio_owAEPlayer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/audio_owAEPlayer.cpp$(DependSuffix): ../ow/audio/owAEPlayer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/audio_owAEPlayer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/audio_owAEPlayer.cpp$(DependSuffix) -MM "../ow/audio/owAEPlayer.cpp"

$(IntermediateDirectory)/audio_owAEPlayer.cpp$(PreprocessSuffix): ../ow/audio/owAEPlayer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/audio_owAEPlayer.cpp$(PreprocessSuffix) "../ow/audio/owAEPlayer.cpp"

$(IntermediateDirectory)/audio_owAudio.cpp$(ObjectSuffix): ../ow/audio/owAudio.cpp $(IntermediateDirectory)/audio_owAudio.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/ow/audio/owAudio.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/audio_owAudio.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/audio_owAudio.cpp$(DependSuffix): ../ow/audio/owAudio.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/audio_owAudio.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/audio_owAudio.cpp$(DependSuffix) -MM "../ow/audio/owAudio.cpp"

$(IntermediateDirectory)/audio_owAudio.cpp$(PreprocessSuffix): ../ow/audio/owAudio.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/audio_owAudio.cpp$(PreprocessSuffix) "../ow/audio/owAudio.cpp"

$(IntermediateDirectory)/buffer_buffer.cpp$(ObjectSuffix): ../ow/buffer/buffer.cpp $(IntermediateDirectory)/buffer_buffer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/ow/buffer/buffer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/buffer_buffer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/buffer_buffer.cpp$(DependSuffix): ../ow/buffer/buffer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/buffer_buffer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/buffer_buffer.cpp$(DependSuffix) -MM "../ow/buffer/buffer.cpp"

$(IntermediateDirectory)/buffer_buffer.cpp$(PreprocessSuffix): ../ow/buffer/buffer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/buffer_buffer.cpp$(PreprocessSuffix) "../ow/buffer/buffer.cpp"

$(IntermediateDirectory)/excel_excel.cpp$(ObjectSuffix): ../ow/excel/excel.cpp $(IntermediateDirectory)/excel_excel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/ow/excel/excel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/excel_excel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/excel_excel.cpp$(DependSuffix): ../ow/excel/excel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/excel_excel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/excel_excel.cpp$(DependSuffix) -MM "../ow/excel/excel.cpp"

$(IntermediateDirectory)/excel_excel.cpp$(PreprocessSuffix): ../ow/excel/excel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/excel_excel.cpp$(PreprocessSuffix) "../ow/excel/excel.cpp"

$(IntermediateDirectory)/excel_excel_def_imp.cpp$(ObjectSuffix): ../ow/excel/excel_def_imp.cpp $(IntermediateDirectory)/excel_excel_def_imp.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/ow/excel/excel_def_imp.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/excel_excel_def_imp.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/excel_excel_def_imp.cpp$(DependSuffix): ../ow/excel/excel_def_imp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/excel_excel_def_imp.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/excel_excel_def_imp.cpp$(DependSuffix) -MM "../ow/excel/excel_def_imp.cpp"

$(IntermediateDirectory)/excel_excel_def_imp.cpp$(PreprocessSuffix): ../ow/excel/excel_def_imp.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/excel_excel_def_imp.cpp$(PreprocessSuffix) "../ow/excel/excel_def_imp.cpp"

$(IntermediateDirectory)/memory_memory.cpp$(ObjectSuffix): ../ow/memory/memory.cpp $(IntermediateDirectory)/memory_memory.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/ow/memory/memory.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/memory_memory.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/memory_memory.cpp$(DependSuffix): ../ow/memory/memory.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/memory_memory.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/memory_memory.cpp$(DependSuffix) -MM "../ow/memory/memory.cpp"

$(IntermediateDirectory)/memory_memory.cpp$(PreprocessSuffix): ../ow/memory/memory.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/memory_memory.cpp$(PreprocessSuffix) "../ow/memory/memory.cpp"

$(IntermediateDirectory)/owZip_owZip.cpp$(ObjectSuffix): ../ow/owZip/owZip.cpp $(IntermediateDirectory)/owZip_owZip.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/ow/owZip/owZip.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/owZip_owZip.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/owZip_owZip.cpp$(DependSuffix): ../ow/owZip/owZip.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/owZip_owZip.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/owZip_owZip.cpp$(DependSuffix) -MM "../ow/owZip/owZip.cpp"

$(IntermediateDirectory)/owZip_owZip.cpp$(PreprocessSuffix): ../ow/owZip/owZip.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/owZip_owZip.cpp$(PreprocessSuffix) "../ow/owZip/owZip.cpp"

$(IntermediateDirectory)/owfile_owfile.cpp$(ObjectSuffix): ../ow/owfile/owfile.cpp $(IntermediateDirectory)/owfile_owfile.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/ow/owfile/owfile.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/owfile_owfile.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/owfile_owfile.cpp$(DependSuffix): ../ow/owfile/owfile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/owfile_owfile.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/owfile_owfile.cpp$(DependSuffix) -MM "../ow/owfile/owfile.cpp"

$(IntermediateDirectory)/owfile_owfile.cpp$(PreprocessSuffix): ../ow/owfile/owfile.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/owfile_owfile.cpp$(PreprocessSuffix) "../ow/owfile/owfile.cpp"

$(IntermediateDirectory)/package_owPackage.cpp$(ObjectSuffix): ../ow/package/owPackage.cpp $(IntermediateDirectory)/package_owPackage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/ow/package/owPackage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/package_owPackage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/package_owPackage.cpp$(DependSuffix): ../ow/package/owPackage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/package_owPackage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/package_owPackage.cpp$(DependSuffix) -MM "../ow/package/owPackage.cpp"

$(IntermediateDirectory)/package_owPackage.cpp$(PreprocessSuffix): ../ow/package/owPackage.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/package_owPackage.cpp$(PreprocessSuffix) "../ow/package/owPackage.cpp"

$(IntermediateDirectory)/package_package_common.cpp$(ObjectSuffix): ../ow/package/package_common.cpp $(IntermediateDirectory)/package_package_common.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/ow/package/package_common.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/package_package_common.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/package_package_common.cpp$(DependSuffix): ../ow/package/package_common.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/package_package_common.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/package_package_common.cpp$(DependSuffix) -MM "../ow/package/package_common.cpp"

$(IntermediateDirectory)/package_package_common.cpp$(PreprocessSuffix): ../ow/package/package_common.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/package_package_common.cpp$(PreprocessSuffix) "../ow/package/package_common.cpp"

$(IntermediateDirectory)/aabb_aabb.cpp$(ObjectSuffix): scene/aabb/aabb.cpp $(IntermediateDirectory)/aabb_aabb.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/scene/aabb/aabb.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/aabb_aabb.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/aabb_aabb.cpp$(DependSuffix): scene/aabb/aabb.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/aabb_aabb.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/aabb_aabb.cpp$(DependSuffix) -MM "scene/aabb/aabb.cpp"

$(IntermediateDirectory)/aabb_aabb.cpp$(PreprocessSuffix): scene/aabb/aabb.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/aabb_aabb.cpp$(PreprocessSuffix) "scene/aabb/aabb.cpp"

$(IntermediateDirectory)/octree_Octree.cpp$(ObjectSuffix): scene/octree/Octree.cpp $(IntermediateDirectory)/octree_Octree.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/scene/octree/Octree.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/octree_Octree.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/octree_Octree.cpp$(DependSuffix): scene/octree/Octree.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/octree_Octree.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/octree_Octree.cpp$(DependSuffix) -MM "scene/octree/Octree.cpp"

$(IntermediateDirectory)/octree_Octree.cpp$(PreprocessSuffix): scene/octree/Octree.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/octree_Octree.cpp$(PreprocessSuffix) "scene/octree/Octree.cpp"

$(IntermediateDirectory)/octree_OctreeRenderNode.cpp$(ObjectSuffix): scene/octree/OctreeRenderNode.cpp $(IntermediateDirectory)/octree_OctreeRenderNode.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/scene/octree/OctreeRenderNode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/octree_OctreeRenderNode.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/octree_OctreeRenderNode.cpp$(DependSuffix): scene/octree/OctreeRenderNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/octree_OctreeRenderNode.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/octree_OctreeRenderNode.cpp$(DependSuffix) -MM "scene/octree/OctreeRenderNode.cpp"

$(IntermediateDirectory)/octree_OctreeRenderNode.cpp$(PreprocessSuffix): scene/octree/OctreeRenderNode.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/octree_OctreeRenderNode.cpp$(PreprocessSuffix) "scene/octree/OctreeRenderNode.cpp"

$(IntermediateDirectory)/md5parser_md5.cpp$(ObjectSuffix): model/md5parser/md5.cpp $(IntermediateDirectory)/md5parser_md5.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/model/md5parser/md5.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/md5parser_md5.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/md5parser_md5.cpp$(DependSuffix): model/md5parser/md5.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/md5parser_md5.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/md5parser_md5.cpp$(DependSuffix) -MM "model/md5parser/md5.cpp"

$(IntermediateDirectory)/md5parser_md5.cpp$(PreprocessSuffix): model/md5parser/md5.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/md5parser_md5.cpp$(PreprocessSuffix) "model/md5parser/md5.cpp"

$(IntermediateDirectory)/md5parser_md5Model.cpp$(ObjectSuffix): model/md5parser/md5Model.cpp $(IntermediateDirectory)/md5parser_md5Model.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/model/md5parser/md5Model.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/md5parser_md5Model.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/md5parser_md5Model.cpp$(DependSuffix): model/md5parser/md5Model.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/md5parser_md5Model.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/md5parser_md5Model.cpp$(DependSuffix) -MM "model/md5parser/md5Model.cpp"

$(IntermediateDirectory)/md5parser_md5Model.cpp$(PreprocessSuffix): model/md5parser/md5Model.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/md5parser_md5Model.cpp$(PreprocessSuffix) "model/md5parser/md5Model.cpp"

$(IntermediateDirectory)/renderer_TextRenderer.cpp$(ObjectSuffix): core/renderer/TextRenderer.cpp $(IntermediateDirectory)/renderer_TextRenderer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/core/core/renderer/TextRenderer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/renderer_TextRenderer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/renderer_TextRenderer.cpp$(DependSuffix): core/renderer/TextRenderer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/renderer_TextRenderer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/renderer_TextRenderer.cpp$(DependSuffix) -MM "core/renderer/TextRenderer.cpp"

$(IntermediateDirectory)/renderer_TextRenderer.cpp$(PreprocessSuffix): core/renderer/TextRenderer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/renderer_TextRenderer.cpp$(PreprocessSuffix) "core/renderer/TextRenderer.cpp"

$(IntermediateDirectory)/lua_lapi.c$(ObjectSuffix): ../ow/script/lua/lapi.c $(IntermediateDirectory)/lua_lapi.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/lapi.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lapi.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lapi.c$(DependSuffix): ../ow/script/lua/lapi.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lapi.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lapi.c$(DependSuffix) -MM "../ow/script/lua/lapi.c"

$(IntermediateDirectory)/lua_lapi.c$(PreprocessSuffix): ../ow/script/lua/lapi.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lapi.c$(PreprocessSuffix) "../ow/script/lua/lapi.c"

$(IntermediateDirectory)/lua_lauxlib.c$(ObjectSuffix): ../ow/script/lua/lauxlib.c $(IntermediateDirectory)/lua_lauxlib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/lauxlib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lauxlib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lauxlib.c$(DependSuffix): ../ow/script/lua/lauxlib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lauxlib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lauxlib.c$(DependSuffix) -MM "../ow/script/lua/lauxlib.c"

$(IntermediateDirectory)/lua_lauxlib.c$(PreprocessSuffix): ../ow/script/lua/lauxlib.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lauxlib.c$(PreprocessSuffix) "../ow/script/lua/lauxlib.c"

$(IntermediateDirectory)/lua_lbaselib.c$(ObjectSuffix): ../ow/script/lua/lbaselib.c $(IntermediateDirectory)/lua_lbaselib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/lbaselib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lbaselib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lbaselib.c$(DependSuffix): ../ow/script/lua/lbaselib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lbaselib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lbaselib.c$(DependSuffix) -MM "../ow/script/lua/lbaselib.c"

$(IntermediateDirectory)/lua_lbaselib.c$(PreprocessSuffix): ../ow/script/lua/lbaselib.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lbaselib.c$(PreprocessSuffix) "../ow/script/lua/lbaselib.c"

$(IntermediateDirectory)/lua_lbitlib.c$(ObjectSuffix): ../ow/script/lua/lbitlib.c $(IntermediateDirectory)/lua_lbitlib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/lbitlib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lbitlib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lbitlib.c$(DependSuffix): ../ow/script/lua/lbitlib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lbitlib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lbitlib.c$(DependSuffix) -MM "../ow/script/lua/lbitlib.c"

$(IntermediateDirectory)/lua_lbitlib.c$(PreprocessSuffix): ../ow/script/lua/lbitlib.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lbitlib.c$(PreprocessSuffix) "../ow/script/lua/lbitlib.c"

$(IntermediateDirectory)/lua_lcode.c$(ObjectSuffix): ../ow/script/lua/lcode.c $(IntermediateDirectory)/lua_lcode.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/lcode.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lcode.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lcode.c$(DependSuffix): ../ow/script/lua/lcode.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lcode.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lcode.c$(DependSuffix) -MM "../ow/script/lua/lcode.c"

$(IntermediateDirectory)/lua_lcode.c$(PreprocessSuffix): ../ow/script/lua/lcode.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lcode.c$(PreprocessSuffix) "../ow/script/lua/lcode.c"

$(IntermediateDirectory)/lua_lcorolib.c$(ObjectSuffix): ../ow/script/lua/lcorolib.c $(IntermediateDirectory)/lua_lcorolib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/lcorolib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lcorolib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lcorolib.c$(DependSuffix): ../ow/script/lua/lcorolib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lcorolib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lcorolib.c$(DependSuffix) -MM "../ow/script/lua/lcorolib.c"

$(IntermediateDirectory)/lua_lcorolib.c$(PreprocessSuffix): ../ow/script/lua/lcorolib.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lcorolib.c$(PreprocessSuffix) "../ow/script/lua/lcorolib.c"

$(IntermediateDirectory)/lua_lctype.c$(ObjectSuffix): ../ow/script/lua/lctype.c $(IntermediateDirectory)/lua_lctype.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/lctype.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lctype.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lctype.c$(DependSuffix): ../ow/script/lua/lctype.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lctype.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lctype.c$(DependSuffix) -MM "../ow/script/lua/lctype.c"

$(IntermediateDirectory)/lua_lctype.c$(PreprocessSuffix): ../ow/script/lua/lctype.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lctype.c$(PreprocessSuffix) "../ow/script/lua/lctype.c"

$(IntermediateDirectory)/lua_ldblib.c$(ObjectSuffix): ../ow/script/lua/ldblib.c $(IntermediateDirectory)/lua_ldblib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/ldblib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_ldblib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_ldblib.c$(DependSuffix): ../ow/script/lua/ldblib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_ldblib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_ldblib.c$(DependSuffix) -MM "../ow/script/lua/ldblib.c"

$(IntermediateDirectory)/lua_ldblib.c$(PreprocessSuffix): ../ow/script/lua/ldblib.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_ldblib.c$(PreprocessSuffix) "../ow/script/lua/ldblib.c"

$(IntermediateDirectory)/lua_ldebug.c$(ObjectSuffix): ../ow/script/lua/ldebug.c $(IntermediateDirectory)/lua_ldebug.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/ldebug.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_ldebug.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_ldebug.c$(DependSuffix): ../ow/script/lua/ldebug.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_ldebug.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_ldebug.c$(DependSuffix) -MM "../ow/script/lua/ldebug.c"

$(IntermediateDirectory)/lua_ldebug.c$(PreprocessSuffix): ../ow/script/lua/ldebug.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_ldebug.c$(PreprocessSuffix) "../ow/script/lua/ldebug.c"

$(IntermediateDirectory)/lua_ldo.c$(ObjectSuffix): ../ow/script/lua/ldo.c $(IntermediateDirectory)/lua_ldo.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/ldo.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_ldo.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_ldo.c$(DependSuffix): ../ow/script/lua/ldo.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_ldo.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_ldo.c$(DependSuffix) -MM "../ow/script/lua/ldo.c"

$(IntermediateDirectory)/lua_ldo.c$(PreprocessSuffix): ../ow/script/lua/ldo.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_ldo.c$(PreprocessSuffix) "../ow/script/lua/ldo.c"

$(IntermediateDirectory)/lua_ldump.c$(ObjectSuffix): ../ow/script/lua/ldump.c $(IntermediateDirectory)/lua_ldump.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/ldump.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_ldump.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_ldump.c$(DependSuffix): ../ow/script/lua/ldump.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_ldump.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_ldump.c$(DependSuffix) -MM "../ow/script/lua/ldump.c"

$(IntermediateDirectory)/lua_ldump.c$(PreprocessSuffix): ../ow/script/lua/ldump.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_ldump.c$(PreprocessSuffix) "../ow/script/lua/ldump.c"

$(IntermediateDirectory)/lua_lfunc.c$(ObjectSuffix): ../ow/script/lua/lfunc.c $(IntermediateDirectory)/lua_lfunc.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/lfunc.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lfunc.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lfunc.c$(DependSuffix): ../ow/script/lua/lfunc.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lfunc.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lfunc.c$(DependSuffix) -MM "../ow/script/lua/lfunc.c"

$(IntermediateDirectory)/lua_lfunc.c$(PreprocessSuffix): ../ow/script/lua/lfunc.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lfunc.c$(PreprocessSuffix) "../ow/script/lua/lfunc.c"

$(IntermediateDirectory)/lua_lgc.c$(ObjectSuffix): ../ow/script/lua/lgc.c $(IntermediateDirectory)/lua_lgc.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/lgc.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lgc.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lgc.c$(DependSuffix): ../ow/script/lua/lgc.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lgc.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lgc.c$(DependSuffix) -MM "../ow/script/lua/lgc.c"

$(IntermediateDirectory)/lua_lgc.c$(PreprocessSuffix): ../ow/script/lua/lgc.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lgc.c$(PreprocessSuffix) "../ow/script/lua/lgc.c"

$(IntermediateDirectory)/lua_linit.c$(ObjectSuffix): ../ow/script/lua/linit.c $(IntermediateDirectory)/lua_linit.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/linit.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_linit.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_linit.c$(DependSuffix): ../ow/script/lua/linit.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_linit.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_linit.c$(DependSuffix) -MM "../ow/script/lua/linit.c"

$(IntermediateDirectory)/lua_linit.c$(PreprocessSuffix): ../ow/script/lua/linit.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_linit.c$(PreprocessSuffix) "../ow/script/lua/linit.c"

$(IntermediateDirectory)/lua_liolib.c$(ObjectSuffix): ../ow/script/lua/liolib.c $(IntermediateDirectory)/lua_liolib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/liolib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_liolib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_liolib.c$(DependSuffix): ../ow/script/lua/liolib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_liolib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_liolib.c$(DependSuffix) -MM "../ow/script/lua/liolib.c"

$(IntermediateDirectory)/lua_liolib.c$(PreprocessSuffix): ../ow/script/lua/liolib.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_liolib.c$(PreprocessSuffix) "../ow/script/lua/liolib.c"

$(IntermediateDirectory)/lua_llex.c$(ObjectSuffix): ../ow/script/lua/llex.c $(IntermediateDirectory)/lua_llex.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/llex.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_llex.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_llex.c$(DependSuffix): ../ow/script/lua/llex.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_llex.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_llex.c$(DependSuffix) -MM "../ow/script/lua/llex.c"

$(IntermediateDirectory)/lua_llex.c$(PreprocessSuffix): ../ow/script/lua/llex.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_llex.c$(PreprocessSuffix) "../ow/script/lua/llex.c"

$(IntermediateDirectory)/lua_lmathlib.c$(ObjectSuffix): ../ow/script/lua/lmathlib.c $(IntermediateDirectory)/lua_lmathlib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/lmathlib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lmathlib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lmathlib.c$(DependSuffix): ../ow/script/lua/lmathlib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lmathlib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lmathlib.c$(DependSuffix) -MM "../ow/script/lua/lmathlib.c"

$(IntermediateDirectory)/lua_lmathlib.c$(PreprocessSuffix): ../ow/script/lua/lmathlib.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lmathlib.c$(PreprocessSuffix) "../ow/script/lua/lmathlib.c"

$(IntermediateDirectory)/lua_lmem.c$(ObjectSuffix): ../ow/script/lua/lmem.c $(IntermediateDirectory)/lua_lmem.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/lmem.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lmem.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lmem.c$(DependSuffix): ../ow/script/lua/lmem.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lmem.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lmem.c$(DependSuffix) -MM "../ow/script/lua/lmem.c"

$(IntermediateDirectory)/lua_lmem.c$(PreprocessSuffix): ../ow/script/lua/lmem.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lmem.c$(PreprocessSuffix) "../ow/script/lua/lmem.c"

$(IntermediateDirectory)/lua_loadlib.c$(ObjectSuffix): ../ow/script/lua/loadlib.c $(IntermediateDirectory)/lua_loadlib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/loadlib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_loadlib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_loadlib.c$(DependSuffix): ../ow/script/lua/loadlib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_loadlib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_loadlib.c$(DependSuffix) -MM "../ow/script/lua/loadlib.c"

$(IntermediateDirectory)/lua_loadlib.c$(PreprocessSuffix): ../ow/script/lua/loadlib.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_loadlib.c$(PreprocessSuffix) "../ow/script/lua/loadlib.c"

$(IntermediateDirectory)/lua_lobject.c$(ObjectSuffix): ../ow/script/lua/lobject.c $(IntermediateDirectory)/lua_lobject.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/lobject.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lobject.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lobject.c$(DependSuffix): ../ow/script/lua/lobject.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lobject.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lobject.c$(DependSuffix) -MM "../ow/script/lua/lobject.c"

$(IntermediateDirectory)/lua_lobject.c$(PreprocessSuffix): ../ow/script/lua/lobject.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lobject.c$(PreprocessSuffix) "../ow/script/lua/lobject.c"

$(IntermediateDirectory)/lua_lopcodes.c$(ObjectSuffix): ../ow/script/lua/lopcodes.c $(IntermediateDirectory)/lua_lopcodes.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/lopcodes.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lopcodes.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lopcodes.c$(DependSuffix): ../ow/script/lua/lopcodes.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lopcodes.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lopcodes.c$(DependSuffix) -MM "../ow/script/lua/lopcodes.c"

$(IntermediateDirectory)/lua_lopcodes.c$(PreprocessSuffix): ../ow/script/lua/lopcodes.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lopcodes.c$(PreprocessSuffix) "../ow/script/lua/lopcodes.c"

$(IntermediateDirectory)/lua_loslib.c$(ObjectSuffix): ../ow/script/lua/loslib.c $(IntermediateDirectory)/lua_loslib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/loslib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_loslib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_loslib.c$(DependSuffix): ../ow/script/lua/loslib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_loslib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_loslib.c$(DependSuffix) -MM "../ow/script/lua/loslib.c"

$(IntermediateDirectory)/lua_loslib.c$(PreprocessSuffix): ../ow/script/lua/loslib.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_loslib.c$(PreprocessSuffix) "../ow/script/lua/loslib.c"

$(IntermediateDirectory)/lua_lparser.c$(ObjectSuffix): ../ow/script/lua/lparser.c $(IntermediateDirectory)/lua_lparser.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/lparser.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lparser.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lparser.c$(DependSuffix): ../ow/script/lua/lparser.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lparser.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lparser.c$(DependSuffix) -MM "../ow/script/lua/lparser.c"

$(IntermediateDirectory)/lua_lparser.c$(PreprocessSuffix): ../ow/script/lua/lparser.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lparser.c$(PreprocessSuffix) "../ow/script/lua/lparser.c"

$(IntermediateDirectory)/lua_lstate.c$(ObjectSuffix): ../ow/script/lua/lstate.c $(IntermediateDirectory)/lua_lstate.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/lstate.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lstate.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lstate.c$(DependSuffix): ../ow/script/lua/lstate.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lstate.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lstate.c$(DependSuffix) -MM "../ow/script/lua/lstate.c"

$(IntermediateDirectory)/lua_lstate.c$(PreprocessSuffix): ../ow/script/lua/lstate.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lstate.c$(PreprocessSuffix) "../ow/script/lua/lstate.c"

$(IntermediateDirectory)/lua_lstring.c$(ObjectSuffix): ../ow/script/lua/lstring.c $(IntermediateDirectory)/lua_lstring.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/lstring.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lstring.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lstring.c$(DependSuffix): ../ow/script/lua/lstring.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lstring.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lstring.c$(DependSuffix) -MM "../ow/script/lua/lstring.c"

$(IntermediateDirectory)/lua_lstring.c$(PreprocessSuffix): ../ow/script/lua/lstring.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lstring.c$(PreprocessSuffix) "../ow/script/lua/lstring.c"

$(IntermediateDirectory)/lua_lstrlib.c$(ObjectSuffix): ../ow/script/lua/lstrlib.c $(IntermediateDirectory)/lua_lstrlib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/lstrlib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lstrlib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lstrlib.c$(DependSuffix): ../ow/script/lua/lstrlib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lstrlib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lstrlib.c$(DependSuffix) -MM "../ow/script/lua/lstrlib.c"

$(IntermediateDirectory)/lua_lstrlib.c$(PreprocessSuffix): ../ow/script/lua/lstrlib.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lstrlib.c$(PreprocessSuffix) "../ow/script/lua/lstrlib.c"

$(IntermediateDirectory)/lua_ltable.c$(ObjectSuffix): ../ow/script/lua/ltable.c $(IntermediateDirectory)/lua_ltable.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/ltable.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_ltable.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_ltable.c$(DependSuffix): ../ow/script/lua/ltable.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_ltable.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_ltable.c$(DependSuffix) -MM "../ow/script/lua/ltable.c"

$(IntermediateDirectory)/lua_ltable.c$(PreprocessSuffix): ../ow/script/lua/ltable.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_ltable.c$(PreprocessSuffix) "../ow/script/lua/ltable.c"

$(IntermediateDirectory)/lua_ltablib.c$(ObjectSuffix): ../ow/script/lua/ltablib.c $(IntermediateDirectory)/lua_ltablib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/ltablib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_ltablib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_ltablib.c$(DependSuffix): ../ow/script/lua/ltablib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_ltablib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_ltablib.c$(DependSuffix) -MM "../ow/script/lua/ltablib.c"

$(IntermediateDirectory)/lua_ltablib.c$(PreprocessSuffix): ../ow/script/lua/ltablib.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_ltablib.c$(PreprocessSuffix) "../ow/script/lua/ltablib.c"

$(IntermediateDirectory)/lua_ltm.c$(ObjectSuffix): ../ow/script/lua/ltm.c $(IntermediateDirectory)/lua_ltm.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/ltm.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_ltm.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_ltm.c$(DependSuffix): ../ow/script/lua/ltm.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_ltm.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_ltm.c$(DependSuffix) -MM "../ow/script/lua/ltm.c"

$(IntermediateDirectory)/lua_ltm.c$(PreprocessSuffix): ../ow/script/lua/ltm.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_ltm.c$(PreprocessSuffix) "../ow/script/lua/ltm.c"

$(IntermediateDirectory)/lua_lua.c$(ObjectSuffix): ../ow/script/lua/lua.c $(IntermediateDirectory)/lua_lua.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/lua.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lua.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lua.c$(DependSuffix): ../ow/script/lua/lua.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lua.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lua.c$(DependSuffix) -MM "../ow/script/lua/lua.c"

$(IntermediateDirectory)/lua_lua.c$(PreprocessSuffix): ../ow/script/lua/lua.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lua.c$(PreprocessSuffix) "../ow/script/lua/lua.c"

$(IntermediateDirectory)/lua_luac.c$(ObjectSuffix): ../ow/script/lua/luac.c $(IntermediateDirectory)/lua_luac.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/luac.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_luac.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_luac.c$(DependSuffix): ../ow/script/lua/luac.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_luac.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_luac.c$(DependSuffix) -MM "../ow/script/lua/luac.c"

$(IntermediateDirectory)/lua_luac.c$(PreprocessSuffix): ../ow/script/lua/luac.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_luac.c$(PreprocessSuffix) "../ow/script/lua/luac.c"

$(IntermediateDirectory)/lua_lundump.c$(ObjectSuffix): ../ow/script/lua/lundump.c $(IntermediateDirectory)/lua_lundump.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/lundump.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lundump.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lundump.c$(DependSuffix): ../ow/script/lua/lundump.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lundump.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lundump.c$(DependSuffix) -MM "../ow/script/lua/lundump.c"

$(IntermediateDirectory)/lua_lundump.c$(PreprocessSuffix): ../ow/script/lua/lundump.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lundump.c$(PreprocessSuffix) "../ow/script/lua/lundump.c"

$(IntermediateDirectory)/lua_lvm.c$(ObjectSuffix): ../ow/script/lua/lvm.c $(IntermediateDirectory)/lua_lvm.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/lvm.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lvm.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lvm.c$(DependSuffix): ../ow/script/lua/lvm.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lvm.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lvm.c$(DependSuffix) -MM "../ow/script/lua/lvm.c"

$(IntermediateDirectory)/lua_lvm.c$(PreprocessSuffix): ../ow/script/lua/lvm.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lvm.c$(PreprocessSuffix) "../ow/script/lua/lvm.c"

$(IntermediateDirectory)/lua_lzio.c$(ObjectSuffix): ../ow/script/lua/lzio.c $(IntermediateDirectory)/lua_lzio.c$(DependSuffix)
	$(CC) $(SourceSwitch) "E:/projects/graphics/ow/script/lua/lzio.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua_lzio.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua_lzio.c$(DependSuffix): ../ow/script/lua/lzio.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua_lzio.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua_lzio.c$(DependSuffix) -MM "../ow/script/lua/lzio.c"

$(IntermediateDirectory)/lua_lzio.c$(PreprocessSuffix): ../ow/script/lua/lzio.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua_lzio.c$(PreprocessSuffix) "../ow/script/lua/lzio.c"

$(IntermediateDirectory)/scriptEngine_ScriptEngine.cpp$(ObjectSuffix): ../ow/script/scriptEngine/ScriptEngine.cpp $(IntermediateDirectory)/scriptEngine_ScriptEngine.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/ow/script/scriptEngine/ScriptEngine.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/scriptEngine_ScriptEngine.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/scriptEngine_ScriptEngine.cpp$(DependSuffix): ../ow/script/scriptEngine/ScriptEngine.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/scriptEngine_ScriptEngine.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/scriptEngine_ScriptEngine.cpp$(DependSuffix) -MM "../ow/script/scriptEngine/ScriptEngine.cpp"

$(IntermediateDirectory)/scriptEngine_ScriptEngine.cpp$(PreprocessSuffix): ../ow/script/scriptEngine/ScriptEngine.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/scriptEngine_ScriptEngine.cpp$(PreprocessSuffix) "../ow/script/scriptEngine/ScriptEngine.cpp"

$(IntermediateDirectory)/log_logger.cpp$(ObjectSuffix): ../ow/owcmn/log/logger.cpp $(IntermediateDirectory)/log_logger.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/projects/graphics/ow/owcmn/log/logger.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/log_logger.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/log_logger.cpp$(DependSuffix): ../ow/owcmn/log/logger.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/log_logger.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/log_logger.cpp$(DependSuffix) -MM "../ow/owcmn/log/logger.cpp"

$(IntermediateDirectory)/log_logger.cpp$(PreprocessSuffix): ../ow/owcmn/log/logger.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/log_logger.cpp$(PreprocessSuffix) "../ow/owcmn/log/logger.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(BuildDir)/$(ProjectName)/Debug/


