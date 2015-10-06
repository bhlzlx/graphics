.PHONY: clean All

All:
	@echo "----------Building project:[ audio -  ]----------"
	@cd "audio" && $(MAKE) -f  "audio.mk"
clean:
	@echo "----------Cleaning project:[ audio -  ]----------"
	@cd "audio" && $(MAKE) -f  "audio.mk" clean
