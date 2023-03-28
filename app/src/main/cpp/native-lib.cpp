#include <android/asset_manager_jni.h>
#include <jni.h>
#include <string>

//void fgGeometryTest(const FgArgs &);

extern "C" JNIEXPORT jstring

JNICALL
Java_com_mobile_myapplication_MainActivity_stringFromJNI(JNIEnv *env, jobject,jobject _assetManager) {

    std::string hello;

    AAssetManager *assetManager = AAssetManager_fromJava(env, _assetManager);
    AAsset *asset = AAssetManager_open(assetManager, "result_6th_sem.pdf", AASSET_MODE_BUFFER);
//    buf[AAsset_read(asset, buf, BUFSIZE)] = 0;
//    AAsset_close(asset);
    size_t assetLength = AAsset_getLength(asset);
    char* buffer = (char*) malloc(assetLength);
    AAsset_read(asset, buffer, assetLength);
    AAsset_close(asset);
//    hello = buffer;
//    hello = buf;
//    try {
//        // We run this test because it doesn't create any temp files, which isn't yet set up to work with Android:
//        fgGeometryTest(FgArgs());
//    }
//    catch (...) {
//        hello += ". Fgbl test failed.";
//    }
    return env->NewStringUTF(hello.c_str());
}