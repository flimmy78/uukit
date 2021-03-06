/*
*******************************************************************************
**  Copyright (c) 2012, 深圳市有限公司, All rights reserved.
**  作者：梁桥江
**  当前版本：v1.0
**  创建日期: 2012.08.06
**  文件说明: 这里的接口主要给mpi 视频编码取视频帧的时候填充帧头使用的
			这些接口其实可以用 paramManage.h 里面的接口实现,但是由于使用
			频率非常高,每个通道的每一帧都用到,paramManage.h 里面的接口都
			涉及到加锁解锁动作,效率有点低,所以专门使用被文档的接口
*******************************************************************************
*/

#include "paramManage.h"
#include "vencParamEasy.h"
#include "debug.h"

/* ===== video ===== */
static VIDEO_HEAD_LOCAL_T g_videoHeadLocal;

uchar VencParamEasyGetVideoStandard()
{
	return g_videoHeadLocal.videoStandard;
}

uchar VencParamEasyGetResolution( int channel )
{
	return g_videoHeadLocal.resolution[channel];
}

uchar VencParamEasyGetFramerate( int channel )
{
	return g_videoHeadLocal.frameRate[channel];
}

void VencParamEasySetVideoStandard( uchar val )
{
	g_videoHeadLocal.videoStandard = val;
}

void VencParamEasySetResolution( int channel, uchar val )
{
	g_videoHeadLocal.resolution[channel] = val;
}

void VencParamEasySetFramerate( int channel, uchar val )
{
	g_videoHeadLocal.frameRate[channel] = val;
}

static int VencParamEasyInit()
{
	int ret, i;
	PARAM_CONFIG_VIDEO_ENCODE_PUBLIC vepp;
	PARAM_CONFIG_VIDEO_ENCODE vep;
	
	ret = ParamGetVideoEncodePublic( &vepp );
	if( 0 == ret )
	{
		g_videoHeadLocal.videoStandard = vepp.videoStandard;
	}
	for( i = 0; i < REAL_CHANNEL_NUM; ++i )
	{
		ret = ParamGetVideoEncode( i, &vep );
		if( 0 == ret )
		{
			g_videoHeadLocal.resolution[i]	= vep.resolution;		
			g_videoHeadLocal.frameRate[i] 	= vep.frameRate;
		}
	}
	return ret;
}

/* ===== audio ===== */

static AUDIO_HEAD_LOCAL_T g_audioHeadLocal;

uchar VencParamEasyGetAudioSampleRate()
{
	return g_audioHeadLocal.sampleRate;
}

uchar VencParamEasyGetAudioBitWidth()
{
	return g_audioHeadLocal.bitWidth;
}

uchar VencParamEasyGetAudioEncodeType()
{
	return g_audioHeadLocal.encodeType;             //MARK: 20171101 淇敼鍊硷紝鍥炴斁闊抽杩樻槸鏈夐敊璇�
 }

uchar VencParamEasyGetAudioChMode()
{
	return g_audioHeadLocal.chMode;
}

void VencParamEasySetAudioSampleRate( uchar val )
{
	g_audioHeadLocal.sampleRate = val;
}

void VencParamEasySetAudioBitWidth( uchar val )
{
	g_audioHeadLocal.bitWidth = val;
}

void VencParamEasySetAudioEncodeType( uchar val )
{
	g_audioHeadLocal.encodeType = val;
}

void VencParamEasySetAudioChMode( uchar val )
{
	g_audioHeadLocal.chMode = val;
}

static int AudioParamEasyInit()
{
	int ret;
	PARAM_CONFIG_AUDIO_ENCODE param;
	ret = ParamGetAudio( &param );
	if( 0 == ret )
	{
		VencParamEasySetAudioSampleRate( param.sampleRate );
		VencParamEasySetAudioBitWidth( param.bitWidth );
		VencParamEasySetAudioEncodeType( param.encodeType );
		VencParamEasySetAudioChMode( param.chMode );
	}
	return ret;
}

int ParamEasyInit()
{
	int ret = -1;
	ret = VencParamEasyInit();
	ret = AudioParamEasyInit();

	
    RtPrint( ret, "[03] %s [%s:%d]\n", __FUNCTION__, __FILE__, __LINE__ );
	return ret;
}

