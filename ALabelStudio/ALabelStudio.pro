TEMPLATE = subdirs

SUBDIRS += \
    client \
    utils \
    widgets



# 定义子项目的编译顺序（依赖关系）
client.depends = \
    utils \
    widgets


