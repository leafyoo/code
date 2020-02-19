function [ output_args ] = img_basic(filename)
    im=imread('0.jpg');
    
    fr=im(:,:,1);   %R通道分量
    fg=im(:,:,2);
    fb=im(:,:,3);
    
    subplot(221); imshow(fr); title('R') ; %subplot(mnp), m-by-n matrix
    subplot(222); imshow(fg); title('G') ; 
    %subplot(223); imshow(fb); title('B') ; 
     
    subplot(223); 
    
    %灰度轮廓
    %subplot(224); imcontour(fb,1); title('灰度轮廓') ; imshow(im)   
    
    %边缘检测
    %edge(fg, 'canny', 0.3); title('edge') ;imshow(im) %0.3为阈值(0~1)
    
    %灰度调整
    %im = imadjust(fr);
    %im = imadjust(fr, [0.5 0.6], [0.4 0.6]);imshow(im)
    
    %直方图均衡
    %[im, T] = histeq(fr);imshow(im); subplot(224); imhist(im,4); %imhist默认参数是256
    
    %色彩增强
    %im = decorrstrech(im);imshow(im)
    
    %滤波
    %im = rgb2gray(im); im = medfilt2(im);imshow(im)
    
    %图像腐蚀,可以突出果果的黑点等
    %se = strel('disk', 11);im = imerode(im, se); imshow(im)
    %图像膨胀
    %se = strel('disk', 11);im = imdilate(im, se); imshow(im)    
    
    %用拉普拉斯锐化图像
    %lapmask = [1 1 1; 1 -8 1; 1 1 1 ]; se = strel('disk', 5);im = imerode(im, se);
    %im = im - imfilter(im, lapmask, 'replicate'); imshow(im)
    
    %图像梯度
    [VG, A, PPG] = colorgrad(im);imshow(VG)  %colorgrad函数是书中的工具箱里的
    
end

