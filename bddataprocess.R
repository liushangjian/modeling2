con21 <- read.xlsx("C:/Users/Administrator/Desktop/DATA2.xlsx",sheetName="Sheet14")
p24=ggplot(data=con21, aes(con21$recept, con21$frequence*100)) +
  geom_bar(stat="identity",width=0.2,color="black", fill="skyblue")+
  geom_smooth(se = FALSE,span=0.3,color="black")+ ##加上平滑线

  geom_point()+
  labs(
    x = "喙长",
    title="generation=150",
    y = "Frequency(%)")+    ## 添加标记


  xlim(0,5)+
  ylim(0,50)+
  theme(
    panel.background = element_rect(fill = "transparent",colour = NA),
    panel.grid.minor = element_blank(),
    panel.grid.major = element_blank(),
    panel.border = element_blank())  ##这个可以去掉背景

con22 <- read.xlsx("C:/Users/Administrator/Desktop/DATA2.xlsx",sheetName="Sheet12")
p23=ggplot(data=con22, aes(con22$recept, con22$frequence*100)) +
  geom_bar(stat="identity",width=0.2,color="black", fill="skyblue")+
  geom_smooth(se = FALSE,span=0.3,color="black")+ ##加上平滑线

  geom_point()+
  labs(
    x = "喙长",
    title="generation=120",
    y = "Frequency(%)")+    ## 添加标记


  xlim(0,5)+
  ylim(0,50)+
  theme(
    panel.background = element_rect(fill = "transparent",colour = NA),
    panel.grid.minor = element_blank(),
    panel.grid.major = element_blank(),
    panel.border = element_blank())  ##这个可以去掉背景

con23 <- read.xlsx("C:/Users/Administrator/Desktop/DATA2.xlsx",sheetName="Sheet10")
p22=ggplot(data=con23, aes(con23$recept, con23$frequence*100)) +
  geom_bar(stat="identity",width=0.2,color="black", fill="skyblue")+
  geom_smooth(se = FALSE,span=0.3,color="black")+ ##加上平滑线

  geom_point()+
  labs(
    x = "喙长",
    title="generation=80",
    y = "Frequency(%)")+    ## 添加标记


  xlim(0,5)+
  ylim(0,50)+
  theme(
    panel.background = element_rect(fill = "transparent",colour = NA),
    panel.grid.minor = element_blank(),
    panel.grid.major = element_blank(),
    panel.border = element_blank())  ##这个可以去掉背景

con24 <- read.xlsx("C:/Users/Administrator/Desktop/DATA2.xlsx",sheetName="Sheet8")
p21=ggplot(data=con24, aes(con24$recept, con24$frequence*100)) +
  geom_bar(stat="identity",width=0.2,color="black", fill="skyblue")+
  geom_smooth(se = FALSE,span=0.3,color="black")+ ##加上平滑线

  geom_point()+
  labs(
    x = "喙长",
    title="generation=40",
    y = "Frequency(%)")+    ## 添加标记


  xlim(0,5)+
  ylim(0,50)+
  theme(
    panel.background = element_rect(fill = "transparent",colour = NA),
    panel.grid.minor = element_blank(),
    panel.grid.major = element_blank(),
    panel.border = element_blank())  ##这个可以去掉背景

con11 <- read.xlsx("C:/Users/Administrator/Desktop/DATA2.xlsx",sheetName="Sheet5")
p11=ggplot(data=con11, aes(con11$recept, con11$frequence*100)) +
  geom_bar(stat="identity",width=0.2,color="black", fill="skyblue")+
  geom_smooth(se = FALSE,span=0.3,color="black")+ ##加上平滑线

  geom_point()+
  labs(
    x = "喙长",
    title="generation=50",
    y = "Frequency(%)")+    ## 添加标记


  xlim(0,5)+
  ylim(0,50)+
  theme(
    panel.background = element_rect(fill = "transparent",colour = NA),
    panel.grid.minor = element_blank(),
    panel.grid.major = element_blank(),
    panel.border = element_blank())  ##这个可以去掉背景


## -----------------------------------------
## model3

con31 <- read.xlsx("C:/Users/Administrator/Desktop/DATA2.xlsx",sheetName="Sheet17")
p31=ggplot(data=con31, aes(con11$recept, con31$frequence*100)) +
  geom_bar(stat="identity",width=0.2,color="black", fill="skyblue")+
  geom_smooth(se = FALSE,span=0.3,color="black")+ ##加上平滑线

  geom_point()+
  labs(
    x = "喙长",
    title="generation=40",
    y = "Frequency(%)")+    ## 添加标记


  xlim(0,5)+
  ylim(0,50)+
  theme(
    panel.background = element_rect(fill = "transparent",colour = NA),
    panel.grid.minor = element_blank(),
    panel.grid.major = element_blank(),
    panel.border = element_blank())  ##这个可以去掉背景


con32 <- read.xlsx("C:/Users/Administrator/Desktop/DATA2.xlsx",sheetName="Sheet19")
p32=ggplot(data=con32, aes(con32$recept, con32$frequence*100)) +
  geom_bar(stat="identity",width=0.2,color="black", fill="skyblue")+
  geom_smooth(se = FALSE,span=0.3,color="black")+ ##加上平滑线

  geom_point()+
  labs(
    x = "喙长",
    title="generation=80",
    y = "Frequency(%)")+    ## 添加标记


  xlim(0,5)+
  ylim(0,50)+
  theme(
    panel.background = element_rect(fill = "transparent",colour = NA),
    panel.grid.minor = element_blank(),
    panel.grid.major = element_blank(),
    panel.border = element_blank())  ##这个可以去掉背景

con33 <- read.xlsx("C:/Users/Administrator/Desktop/DATA2.xlsx",sheetName="Sheet21")
p33=ggplot(data=con33, aes(con33$recept, con33$frequence*100)) +
  geom_bar(stat="identity",width=0.2,color="black", fill="skyblue")+
  geom_smooth(se = FALSE,span=0.3,color="black")+ ##加上平滑线

  geom_point()+
  labs(
    x = "喙长",
    title="generation=120",
    y = "Frequency(%)")+    ## 添加标记


  xlim(0,5)+
  ylim(0,50)+
  theme(
    panel.background = element_rect(fill = "transparent",colour = NA),
    panel.grid.minor = element_blank(),
    panel.grid.major = element_blank(),
    panel.border = element_blank())  ##这个可以去掉背景

con34 <- read.xlsx("C:/Users/Administrator/Desktop/DATA2.xlsx",sheetName="Sheet23")
p34=ggplot(data=con34, aes(con34$recept, con34$frequence*100)) +
  geom_bar(stat="identity",width=0.2,color="black", fill="skyblue")+
  geom_smooth(se = FALSE,span=0.3,color="black")+ ##加上平滑线

  geom_point()+
  labs(
    x = "喙长",
    title="generation=150",
    y = "Frequency(%)")+    ## 添加标记


  xlim(0,5)+
  ylim(0,50)+
  theme(
    panel.background = element_rect(fill = "transparent",colour = NA),
    panel.grid.minor = element_blank(),
    panel.grid.major = element_blank(),
    panel.border = element_blank())  ##这个可以去掉背景


con35 <- read.xlsx("C:/Users/Administrator/Desktop/DATA2.xlsx",sheetName="Sheet25")
p35=ggplot(data=con35, aes(con35$recept, con35$frequence*100)) +
  geom_bar(stat="identity",width=0.2,color="black", fill="skyblue")+
  geom_smooth(se = FALSE,span=0.3,color="black")+ ##加上平滑线

  geom_point()+
  labs(
    x = "喙长",
    title="generation=200",
    y = "Frequency(%)")+    ## 添加标记


  xlim(0,5)+
  ylim(0,50)+
  theme(
    panel.background = element_rect(fill = "transparent",colour = NA),
    panel.grid.minor = element_blank(),
    panel.grid.major = element_blank(),
    panel.border = element_blank())  ##这个可以去掉背景


## -------------------------------------
## 频率-世代图
con <- read.xlsx("C:/Users/Administrator/Desktop/DATA2.xlsx",sheetName="Sheet26")
ggplot(data=con,aes(x=con$generation,y=con$frequency*100,group=1))+

  geom_line()+

  geom_point()+

  labs(title = "频率-世代分布",
       x = "generation",
       y = "Frequency(%)")+
  scale_x_continuous(breaks=seq(0,330,30))+
  xlim(0,320)+
  ylim(0,100)

## ------------------------------------
## 多图绘制
## multiplot()
# Multiple plot function
#
# ggplot objects can be passed in ..., or to plotlist (as a list of ggplot objects)
# - cols:   Number of columns in layout
# - layout: A matrix specifying the layout. If present, 'cols' is ignored.
#
# If the layout is something like matrix(c(1,2,3,3), nrow=2, byrow=TRUE),
# then plot 1 will go in the upper left, 2 will go in the upper right, and
# 3 will go all the way across the bottom.
#
multiplot <- function(..., plotlist=NULL, file, cols=1, layout=NULL) {
  library(grid)

  # Make a list from the ... arguments and plotlist
  plots <- c(list(...), plotlist)

  numPlots = length(plots)

  # If layout is NULL, then use 'cols' to determine layout
  if (is.null(layout)) {
    # Make the panel
    # ncol: Number of columns of plots
    # nrow: Number of rows needed, calculated from # of cols
    layout <- matrix(seq(1, cols * ceiling(numPlots/cols)),
                     ncol = cols, nrow = ceiling(numPlots/cols))
  }

  if (numPlots==1) {
    print(plots[[1]])

  } else {
    # Set up the page
    grid.newpage()
    pushViewport(viewport(layout = grid.layout(nrow(layout), ncol(layout))))

    # Make each plot, in the correct location
    for (i in 1:numPlots) {
      # Get the i,j matrix positions of the regions that contain this subplot
      matchidx <- as.data.frame(which(layout == i, arr.ind = TRUE))

      print(plots[[i]], vp = viewport(layout.pos.row = matchidx$row,
                                      layout.pos.col = matchidx$col))
    }
  }
}

