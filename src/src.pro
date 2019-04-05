SUBDIRS += \
    controller \
    model \
    core \
    console \

controller.subdirs = $$PWD/core/controller
model.subdirs = $$PWD/core/model
core.subdirs = $$PWD/core
console.subdirs = $$PWD/console

core.depends = controller model console
