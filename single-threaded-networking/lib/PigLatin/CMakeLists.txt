add_library(pigLatin
            PigLatinTranslator.cpp
            )

set_property(TARGET pigLatin PROPERTY CXX_STANDARD 14)

install(TARGETS pigLatin
  ARCHIVE DESTINATION lib
)