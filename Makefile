.PHONY: clean All

All:
	@echo "----------Building project:[ ResourceManager - Debug ]----------"
	@cd "ResourceManager" && $(MAKE) -f  "ResourceManager.mk"
clean:
	@echo "----------Cleaning project:[ ResourceManager - Debug ]----------"
	@cd "ResourceManager" && $(MAKE) -f  "ResourceManager.mk" clean
