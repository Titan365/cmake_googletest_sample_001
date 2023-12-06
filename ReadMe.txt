2023/12/07
GoogleTestのサンプル

/cmake_googletest_sample_001
├/gtest        :GoogleTest本体
├/target       :テスト対象
├/test_code    :テストコード
├CMakeLists.txt:CMakeファイル
└ReadMe.txt    :本ファイル

「/cmake_googletest_sample_001」のフォルダをVisualStdioで開くとCMakeが自動で動作する。そのあとBuild実行。
　参考：https://qiita.com/tapitapi/items/ba0daba1421ffbb0713b


lcovをする場合はMsys起動し下記で生成。
cd /cmake_googletest_sample_001/build/CMakeFiles/test_sample.dir
lcov -c -d . -o cmake_sample.info
genhtml cmake_sample.info
