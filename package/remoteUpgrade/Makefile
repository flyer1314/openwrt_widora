#像其他package一样添加规则
include $(TOPDIR)/rules.mk

#包的名字，可以随便取
PKG_NAME:=remoteUpgrade
#包的版本，自定义
PKG_RELEASE:=1
PKG_VERSION:=0.0

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)

#读取package规则
include $(INCLUDE_DIR)/package.mk

#这里的宏配置的是在make menuconfig中的选项
define Package/remoteUpgrade
	SECTION:=net
	CATEGORY:=Extra packages
	TITLE:=Remote Upgrade The Firmware
endef

#创建包编译位置
define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

#对目标文件产出位置做安排，如果不想打包进FW，需移除此项
define Package/remoteUpgrade/install
	$(INSTALL_DIR)	$(1)/tmp
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/remoteUpgrade $(1)/tmp/
endef

$(eval $(call BuildPackage,remoteUpgrade))
