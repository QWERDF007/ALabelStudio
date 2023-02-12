TEMPLATE = subdirs

SUBDIRS += \
    client \
    tests \
    utils



# 定义子项目的编译顺序（依赖关系）
client.depends = \
    utils


