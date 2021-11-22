include $(TOPDIR)/rules.mk

PKG_NAME:=domlog
PKG_RELEASE:=1
PKG_VERSION:=1.0.0
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/domlog
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=domlog
	DEPENDS:=+libdomlog +libargp
endef

define Package/domlog/description
	domlog reader
endef

define Package/domlog/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/domlog $(1)/usr/bin/domlog
endef

$(eval $(call BuildPackage,domlog))
