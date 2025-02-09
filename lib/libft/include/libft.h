/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:15:03 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/06 12:17:43 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*=-=-=-=-=-=-=-=-INTO-=-=-=-=-=-=-=-=*/

int		ft_toupper( int character );
int		ft_tolower( int character );

/*=-=-=-=-=-=-=-=-IS-=-=-=-=-=-=-=-=*/

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
void	ft_free_array(char **array);
int		ft_array_size(char	**array);
void	error(void);

/*=-=-=-=-=-=-=-=-MEM-=-=-=-=-=-=-=-=*/

void	*ft_calloc(size_t elementCount, size_t elementSize);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memchr( const void *memoryBlock, int searchedChar, size_t size );
int		ft_memcmp( const void *pointer1, const void *pointer2, size_t size );

/*=-=-=-=-=-=-=-=-PUT-=-=-=-=-=-=-=-=*/

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*=-=-=-=-=-=-=-=-STRINT-=-=-=-=-=-=-=-=*/

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr( const char *string, int searchedChar );
char	*ft_strrchr( const char *string, int searchedChar );
int		ft_strncmp( const char *first, const char *second, size_t length );
char	*ft_strdup(char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strnstr( const char *big, const char *little, size_t len);
int		ft_atoi( const char *nptr);
char	**ft_split(char *s, char c);
char	*ft_itoa(int n);
void	ft_swap(int *a, int *b);
void	ft_freestr(char	**str);
int		ft_tablen(char	**tab);

/*=-=-=-=-=-=-=-=-LST-=-=-=-=-=-=-=-=*/

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*=-=-=-=-=-=-=-=-ERROR-=-=-=-=-=-=-=-=*/

void	ft_error(void);

#endif
