cc_test(
    name = "test",
    srcs = glob(["*.cpp"]),
    copts = ["-std=c++1z", "-Iexternal/gtest/include"],
    deps = ["@gtest//:main"],
    visibility = ["//visibility:public"],
    timeout="short"
)
