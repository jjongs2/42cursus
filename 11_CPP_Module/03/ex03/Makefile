NAME = diamondtrap

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP

SRCDIR = .
INCDIR = .
TMPDIR = ./tmp

SRC = $(wildcard *.cpp)

SRCS = $(SRC)
OBJS = $(addprefix $(TMPDIR)/,$(SRCS:.cpp=.o))
DEPS = $(OBJS:.o=.d)

.DEFAULT_GOAL = all

-include $(DEPS)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) -o $@ $^

$(OBJS): | $(TMPDIR)

$(TMPDIR):
	mkdir -p $@

$(TMPDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) -I$(INCDIR) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(TMPDIR)

fclean:
	$(MAKE) -s clean
	$(RM) $(NAME)

re:
	$(MAKE) -s fclean
	$(MAKE) -s all

.PHONY: all clean fclean re
