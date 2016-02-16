#
#
#

install-zsh-compdef: _template.zsh
	@cat _template.zsh | sed "s/TARGET/$(TARGET)/g" > _$(TARGET).zsh
	install -pd $(PREFIX)/share/$(TARGET)/compdef
	install -pm 644 _$(TARGET).zsh $(PREFIX)/share/$(TARGET)/compdef/

.PHONY: install-zsh-compdef
