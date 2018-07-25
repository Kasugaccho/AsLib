//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - AsCu
//
//                    §ìÒ: ªÁ¿å (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
#if defined(ASLIB_INCLUDE_DL) //DxLib
	//`ææn
	using OriginatorTexture = int;
	//CPUæn
	using OriginatorImage = int;
	//å¹ºn
	using OriginatorBGM = int;
	//¹ºn
	using OriginatorSE = int;
	//®æn
	using OriginatorMovie = int;
	//¶n
	using OriginatorFont = int;
	//wiæn
	using OriginatorScreen = int;

	inline bool checkTexture(const OriginatorTexture& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkImage(const OriginatorImage& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkBGM(const OriginatorBGM& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkSE(const OriginatorSE& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkMovie(const OriginatorMovie& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkFont(const OriginatorFont& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkScreen(const OriginatorScreen& ori_) { return (ori_ == -1) ? false : true; }

#elif defined(ASLIB_INCLUDE_S3) //Siv3D
	//`ææn
	using OriginatorTexture = s3d::Texture;
	//CPUæn
	using OriginatorImage = s3d::Image;
	//å¹ºn
	using OriginatorBGM = s3d::Audio;
	//¹ºn
	using OriginatorSE = s3d::Audio;
	//®æn
	using OriginatorMovie = s3d::VideoWriter;
	//¶n
	using OriginatorFont = s3d::Font;
	//wiæn
	using OriginatorScreen = s3d::Texture;

	inline bool checkTexture(const OriginatorTexture& ori_) { return (!ori_) ? false : true; }
	inline bool checkImage(const OriginatorImage& ori_) { return (!ori_) ? false : true; }
	inline bool checkBGM(const OriginatorBGM& ori_) { return (!ori_) ? false : true; }
	inline bool checkSE(const OriginatorSE& ori_) { return (!ori_) ? false : true; }
	inline bool checkMovie(const OriginatorMovie& ori_) { return (!ori_) ? false : true; }
	inline bool checkFont(const OriginatorFont& ori_) { return (!ori_) ? false : true; }
	inline bool checkScreen(const OriginatorScreen& ori_) { return (!ori_) ? false : true; }

#elif defined(ASLIB_INCLUDE_OF)
	//`ææn
	using OriginatorTexture = ofImage;
	//CPUæn
	using OriginatorImage = int32_t;
	//å¹ºn
	using OriginatorBGM = int32_t;
	//¹ºn
	using OriginatorSE = int32_t;
	//®æn
	using OriginatorMovie = int32_t;
	//¶n
	using OriginatorFont = ofTrueTypeFont;
	//wiæn
	using OriginatorScreen = int32_t;
#elif defined(ASLIB_INCLUDE_TP)
	//`ææn
	using OriginatorTexture = int32_t;
	//CPUæn
	using OriginatorImage = int32_t;
	//å¹ºn
	using OriginatorBGM = int32_t;
	//¹ºn
	using OriginatorSE = int32_t;
	//®æn
	using OriginatorMovie = int32_t;
	//¶n
	using OriginatorFont = int32_t;
	//wiæn
	using OriginatorScreen = int32_t;

	inline bool checkTexture(const OriginatorTexture& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkImage(const OriginatorImage& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkBGM(const OriginatorBGM& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkSE(const OriginatorSE& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkMovie(const OriginatorMovie& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkFont(const OriginatorFont& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkScreen(const OriginatorScreen& ori_) { return (ori_ == -1) ? false : true; }

#else //Console
	//`ææn
	using OriginatorTexture = int32_t;
	//CPUæn
	using OriginatorImage = int32_t;
	//å¹ºn
	using OriginatorBGM = int32_t;
	//¹ºn
	using OriginatorSE = int32_t;
	//®æn
	using OriginatorMovie = int32_t;
	//¶n
	using OriginatorFont = int32_t;
	//wiæn
	using OriginatorScreen = int32_t;

	inline bool checkTexture(const OriginatorTexture& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkImage(const OriginatorImage& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkBGM(const OriginatorBGM& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkSE(const OriginatorSE& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkMovie(const OriginatorMovie& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkFont(const OriginatorFont& ori_) { return (ori_ == -1) ? false : true; }
	inline bool checkScreen(const OriginatorScreen& ori_) { return (ori_ == -1) ? false : true; }

#endif
}
