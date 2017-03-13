cc_test(
    name = "test",
    srcs = glob(["test/test.cc",
            "include/*.h"]),
    copts = ["-Iexternal/gtest/include"],
    deps = [
        "@gtest//:main",
        ],
    )
