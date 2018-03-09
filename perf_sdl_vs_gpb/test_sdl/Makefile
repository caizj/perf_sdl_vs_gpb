include $(OB_REL)/etc/NGbasedefine.mk

DEST=sdl_test
DEST_TYPE=BIN

DEST_SOURCES= sdl_test.cpp

CALLED_SDL=sdl_def.sdl

SDL_INC_PATH=./

USER_LIBRARIES=	public_sdl_basic$(BUILDTYPE) \
                cdk_foundation$(BUILDTYPE) \
                boost_thread

USER_DEFS += CDK_ENABLE_BENCHMARK
				
include $(OB_REL)/etc/NGCmake

